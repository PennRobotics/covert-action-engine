// SDL2 Audio Library by Nikita Lisitsa, unified
#include "lisyarus.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>  // TODO: only needed for WAV?

/// #include "psemek/geom/math.hpp"
/// #include "psemek/log/log.hpp"
/// #include "psemek/prof/profiler.hpp"
/// #include "psemek/sdl2/init.hpp"
/// #include "psemek/util/at_scope_exit.hpp"
/// #include "psemek/util/to_string.hpp"

/// #include <atomic>
/// #include <cmath>
/// #include <memory>
#include <mutex>
/// #include <optional>
/// #include <vector>


// Library functions

template <typename F>
struct at_scope_exit {
	F f;
	at_scope_exit(F f) : f(f)  {}
	~at_scope_exit()  { f(); }
};

template <typename X, typename T>
X lerp(const X& x0, const X& x1, const T& t)  { return x0 * (T(1) - t) + x1 * t; }

struct sdl_initializer {
	sdl_initializer()  { /* TODO */ SDL_Init(0); }
	~sdl_initializer()  { SDL_Quit(); }

	static std::shared_ptr<sdl_initializer> instance() {
		static std::weak_ptr<sdl_initializer> ptr;
		if (auto p = ptr.lock(); p)  { return p; }
		auto p = std::make_shared<sdl_initializer>();
		ptr = p;
		return p;
	}
};

struct subsystem_initializer {
	std::shared_ptr<sdl_initializer> sdl_init;
	std::uint32_t subsystems;

	subsystem_initializer(std::uint32_t subsystems) : sdl_init(sdl_initializer::instance()) , subsystems(subsystems) {
		/* TODO */ SDL_InitSubSystem(subsystems);
	}
	~subsystem_initializer()  { SDL_QuitSubSystem(subsystems); }
};

std::shared_ptr<void> init(std::uint32_t subsystems) {
	return std::make_shared<subsystem_initializer>(subsystems);
}


// RESAMPLER
resampler::resampler(float ratio, float smoothness)
    : ratio_(ratio)
    , smoothness_multiplier_( smoothness_to_multiplier(smoothness) )
    , real_ratio_(ratio)
{}

const float resampler::ratio()  { return ratio_.load(); }

float resampler::ratio(float value)  { return ratio_.exchange(value); }

const float resampler::smoothness()  { return multiplier_to_smoothness(smoothness_multiplier_.load()); }

float resampler::smoothness(float value) {
    return multiplier_to_smoothness(smoothness_multiplier_.exchange(smoothness_to_multiplier(value)));
}

void resampler::feed(std::span<const float> samples) {
    result_.clear();

    if (samples.empty())  { return; }

    const float ratio = ratio_.load();
    const float smoothness_multiplier = smoothness_multiplier_.load();

    while (position_ < 0) {
        result_.push_back(geom::lerp(last_sample_[0], samples[0], position_frac_));
        result_.push_back(geom::lerp(last_sample_[1], samples[1], position_frac_));
        real_ratio_ += (ratio - real_ratio_) * smoothness_multiplier;
        advance(1.f / real_ratio_);
    }

    while (2 * position_ + 3 < samples.size()) {
        result_.push_back(geom::lerp(samples[2 * position_ + 0], samples[2 * position_ + 2], position_frac_));
        result_.push_back(geom::lerp(samples[2 * position_ + 1], samples[2 * position_ + 3], position_frac_));
        real_ratio_ += (ratio - real_ratio_) * smoothness_multiplier;
        advance(1.f / real_ratio_);
    }

    position_ -= static_cast<int>(samples.size()) / 2;

    last_sample_[0] = samples[samples.size() - 2];
    last_sample_[1] = samples[samples.size() - 1];
}

void resampler::advance(float delta) {
    position_frac_ += delta;
    auto floor = static_cast<int>(std::floor(position_frac_));
    position_ += floor;
    position_frac_ -= floor;
}


// STEREO
namespace {
struct stereo_impl : stream {
    stereo_impl(stream_ptr left, stream_ptr right) : left_(std::move(left)) , right_(std::move(right))  {}

    const std::optional<std::size_t> length() override {
        auto left = left_->length();
        auto right = right_->length();

        if (left && right)  { return std::min(*left, *right); }
        return left ? left : right;
    }

    const std::size_t played() override {
        return std::min(left_->played(), right_->played());
    }

    std::size_t read(float* data, std::size_t sample_count) override {
        if (buffer_.size() < sample_count)  { buffer_.resize(sample_count); }

        auto right_result = right_->read(data, sample_count);
        auto left_result = left_->read(buffer_.data(), sample_count);

        auto result = std::min(right_result, left_result);

        {
            auto begin = buffer_.data();
            auto end = buffer_.data() + result;
            auto dst = data;
            for (; begin < end; begin += 2, dst += 2)  { *dst = *begin; }
        }

        return result;
    }

private:
stream_ptr left_, right_;
std::vector<float> buffer_;
};
}

stream_ptr stereo(stream_ptr left, stream_ptr right) {
    return std::make_shared<stereo_impl>(std::move(left), std::move(right));
}


// MIXER
namespace {
struct mixer_impl final : mixer , std::enable_shared_from_this<mixer_impl> {
    channel_ptr add(stream_ptr stream) override;

    std::size_t read(float* data, std::size_t sample_count) override;

    const std::optional<std::size_t> length() override  { return std::nullopt; }

    const std::size_t played() override  { return played_.load(); }

private:
    std::vector<channel_ptr> channels_;
    std::vector<channel_ptr> alive_channels_;

    std::vector<float> buffer_;

    std::mutex new_channels_mutex_;
    std::vector<channel_ptr> new_channels_;

    std::atomic<std::size_t> played_ {0};
};

channel_ptr mixer_impl::add(stream_ptr stream) {
    auto result = std::make_shared<channel>(std::move(stream));

    { std::lock_guard lock{new_channels_mutex_}; new_channels_.push_back(result); }

    return result;
}

std::size_t mixer_impl::read(float* data, std::size_t sample_count) {

    {
        std::vector<channel_ptr> new_channels;

        { std::lock_guard lock{new_channels_mutex_}; new_channels = std::move(new_channels_); }

        for (auto& ch : new_channels)  { channels_.push_back(std::move(ch)); }
    }

    std::fill(data, data + sample_count, 0.f);

    buffer_.resize(sample_count);

    for (auto& ch : channels_) {
        auto stream = ch->stream();
        if (!stream)  { continue; }

        auto read = stream->read(buffer_.data(), sample_count);

        {
            auto begin = buffer_.data();
            auto end = begin + read;
            auto dst = data;
            for (; begin < end; )  { *dst++ += *begin++; }
        }

        if (read < sample_count)  { ch->stop(); continue; }

        alive_channels_.push_back(std::move(ch));
    }

    std::swap(channels_, alive_channels_);
    alive_channels_.clear();

    played_.fetch_add(sample_count);

    return sample_count;
}
}

mixer_ptr make_mixer()  { return std::make_shared<mixer_impl>(); }


// TRACK (RAW/WAV)
track_ptr load_raw(std::span<const float> data)  { return make_duplicator(make_recorder(data)); }  // TODO: const?

track_ptr load_raw(std::vector<float> data)  { return make_duplicator(make_recorder(std::move(data))); }

namespace {
std::vector<float> convert_audio(const SDL_AudioSpec& spec, std::uint8_t* samples, std::size_t length) {
    if (spec.channels > 2) {
        /// throw std::runtime_error(std::to_string("Can't convert audio with ", static_cast<int>(spec.channels), " channels"));
    }

    if (spec.freq != audio::frequency) {
        /// throw std::runtime_error(util::to_string("Can't convert audio with frequency ", spec.freq));
    }

    if (spec.format != AUDIO_S16SYS) {
        /// throw std::runtime_error(util::to_string("Can't convert audio with format ", spec.format));
    }

    auto p = reinterpret_cast<std::int16_t*>(samples);

    std::vector<float> result;

    if (spec.channels == 1) {
        result.resize(length);
        for (std::size_t i = 0; i < length / 2; ++i) {
            float v = (p[i] * 2.f + 1.f) / 65536.f;
            result[2 * i + 0] = v;
            result[2 * i + 1] = v;
        }
    } else {
        result.resize(length / 2);
        for (std::size_t i = 0; i < length / 2; ++i) {
            result[i] = (p[i] * 2.f + 1.f) / 65536.f;
        }
    }

    return result;
}
}

track_ptr load_wav(std::span<const char> data) {
    SDL_AudioSpec spec;
    std::uint8_t* samples;
    std::uint32_t length;
    if (!SDL_LoadWAV_RW(SDL_RWFromConstMem(data.data(), data.size()), 1, &spec, &samples, &length)) {
        /// sdl2::fail("SDL_LoadWAV_RW failed:");
    }

    util::at_scope_exit release_samples(  [samples]{ SDL_FreeWAV(samples); }  );
    return make_duplicator(make_recorder(convert_audio(spec, samples, length)));
}

track_ptr load_wav(const std::vector<char>& data)  { return load_wav(std::span<const char>(data)); }  // TODO: const?


// RECORDER
namespace {
struct recorder_impl : recorder {
    recorder_impl(stream_ptr stream) : stream_(std::move(stream))  {}
    recorder_impl(std::vector<float> samples) : storage_(std::move(samples)) , samples_(storage_)  {}
    recorder_impl(std::span<cosnt float> samples) : samples_(samples)  {}

    const std::optional<std::size_t> length() override {
        return stream_ ? stream_->length() : storage_.size();
    }

    std::size_t request(std::size_t samples) override {
        if (!stream_)  { return 0; }

        if (storage_.size() < samples_.size() + samples) {
            storage_.resize(std::max<std::size_t>(samples, storage_.size() * 2));
            samples_ = {storage_.data(), storage_.data() + samples_.size()};
        }

        auto result = stream_->read(storage_.data() + samples_.size(), samples);
        samples_ = {storage_.data(), storage_.data() + samples_.size() + result};
        return result;
    }

    const std::span<const float> buffer() override  { return samples_; }

private:
    stream_ptr stream_;
    std::vector<float> storage_;
    std::span<const float> samples_;
};
}

std::shared_ptr<recorder> make_recorder(stream_ptr stream) {
    return std::make_shared<recorder_impl>(std::move(stream));
}

std::shared_ptr<recorder> make_recorder(std::vector<float> samples) {
    if ((samples.size() % 2) != 0)  { throw std::runtime_error("bad sample count"); }
    return std::make_shared<recorder_impl>(std::move(samples));
}

std::shared_ptr<recorder> make_recorder(std::span<const float> samples) {
    if ((samples.size() % 2) != 0)  { throw std::runtime_error("bad sample count"); }
    return std::make_shared<recorder_impl>(samples);
}


// DUPLICATE
namespace {
struct duplicate_stream_impl : stream {
    duplicate_stream_impl(std::shared_ptr<recorder> recorder) : recorder_(std::move(recorder))  {}

    const std::optional<std::size_t> length() override  { return recorder_->length(); }

    const std::size_t played() override  { return played_.load(); }

    std::size_t read(float* data, std::size_t sample_count) override {
        auto buffer = recorder_->buffer();
        auto played = played_.load();
        if (buffer.size() < played + sample_count) {
            recorder_->request(sample_count);
            buffer = recorder_->buffer();
        }

        auto count = std::min<std::size_t>(sample_count, buffer.size() - played);
        std::copy(buffer.data() + played, buffer.data() + played + count, data);
        played_.fetch_add(count);
        return count;
    }

private:
    std::shared_ptr<recorder> recorder_;
    std::atomic<std::size_t> played_ {0};
};

struct duplicate_track_impl : track {
    duplicate_track_impl(std::shared_ptr<recorder> recorder) : recorder_(std::move(recorder))  {}

    const stream_ptr stream() override {
        return std::make_shared<duplicate_stream_impl>(recorder_);
    }

    const std::optional<std::size_t> length() override  { return recorder_->length(); }

private:
    std::shared_ptr<recorder> recorder_;
};
}

track_ptr make_duplicator(std::shared_ptr<recorder> recorder) {
    return std::make_shared<duplicate_track_impl>(std::move(recorder));
}


// ENGINE
struct engine::impl {
    std::shared_ptr<void> sdl_init;

    SDL_AudioDeviceID device;

    std::vector<float> buffer;
    bool thread_registered = false;  // TODO: curly braces for consistency?

    channel_ptr output;

    impl();
    ~impl();

    static void callback(void* userdata, std::uint8_t* stream, int len);
};

engine::impl::impl() : sdl_init(init(SDL_INIT_AUDIO)) {
    SDL_AudioSpec desired;
    SDL_AudioSpec obtained;

    desired.freq = frequency;
    desired.channels = 2;
    desired.format = AUDIO_S16SYS;
    desired.samples = 256;
    desired.callback = &callback;
    desired.userdata = this;

    if (device = SDL_OpenAudioDevice(nullptr, 0, &desired, &obtained, 0); device == 0) {
        /// sdl2::fail("SDL_OpenAudioDevice failed:");
    }

    /*
    log::info()
        << "Initialized audio: "
        << static_cast<int>(obtained.channels)
        << " channels, "
        << obtained.freq
        << " Hz, "
        << obtained.samples
        << " samples";
    // */

    buffer.resize(obtained.samples* obtained.channels);
    output = std::make_shared<channel>();
    SDL_PauseAudioDevice(device, 0);
}

engine::impl::~impl()  { SDL_CloseAudioDevice(device); }

void engine::impl::callback(void* userdata, std::uint8_t* dst_u8, int len) {
    /// static const std::string profiler_str = "audio";
    /// prof::profiler prof(profiler_str);

    auto self = static_cast<impl*>(userdata);
    stream_ptr output = self->output->stream();
    std::int16_t* dst = reinterpret_cast<std::int16_t*>(dst_u8);

    /// if (!self->thread_registered)  { log::register_thread("audio"); self->thread_registered = true; }
    if (!self->thread_registered)  { self->thread_registered = true; }

    const std::size_t size = len / 2;
    std::size_t read = 0;
    if (output)  { read = output->read(self->buffer.data(), size); }
    std::fill(self->buffer.data() + read, self->buffer.data() + size, 0.f);

    for (auto s : self->buffer) {
        *dst++ = static_cast<std::int16_t>(std::max(std::min((65535.f * s - 1.f) / 2.f, 32767.f), -32768.f));
    }
}

engine::engine() : pimpl_(make_impl())  {}
engine::~engine() = default;

channel_ptr engine::output()  { return impl().output; }

