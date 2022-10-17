#pragma once
/** SDL2 Audio Library by Nikita Lisitsa, unified
 *
 * Effects, waveform generators, and converters are external.
 *
 *     DEPENDENCY DIAGRAM: (incomplete)
 *
 *                      duration <--- constants
 *                                        :
 *           +----------------------+     :
 *           |                      |     :
 *           |                      |     :
 *           +---------+--> mixer   |     :
 *           |         |            |     :
 *   stream -+--> channel ----------+-> engine
 *           |                      |
 *           +-->  track  ----+-----+
 *           |                |
 *           +--> recorder ---+--> duplicate
 *           |                |
 *           +----------------+
 */

#include "psemek/geom/constants.hpp"
/// #include "psemek/util/pimpl.hpp"
/// #include "psemek/io/stream.hpp"

#include <atomic>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <span>
#include <string_view>
#include <utility>
#include <vector>


// CONSTANTS
constexpr int frequency = 44100;
constexpr float inv_frequency = 1.f / frequency;
constexpr double pi = 3.141592653589793238l;

inline std::int64_t  seconds_to_samples(float seconds)  { return static_cast<std::int64_t>(2 * std::round(seconds * frequency)); }
inline float  samples_to_seconds(std::int64_t samples)  { return static_cast<float>(samples) * 0.5f * inv_frequency; }
inline float  to_db(float amplitude)  { return 10.f * std::log10(amplitude); }
inline float  from_db(float db)  { return std::pow(10.f, db / 10.f); }


// DURATION
struct duration {
    duration() : samples_{0}  {}
    duration(std::int64_t samples) : samples_{samples}  {}
    duration(std::size_t samples) : samples_{samples}  {}
    duration(float seconds) : samples_{seconds_to_samples(seconds)}  {}
    duration(const duration& other) = default;

    const float  seconds()  { return samples_to_seconds(samples_); }
    const std::int64_t  samples()  { return samples_; }

    duration&  operator+=(const duration& other)  { samples_ += other.samples_; return *this; }
    duration&  operator-=(const duration& other)  { samples_ -= other.samples_; return *this; }

    friend duration  operator+(const duration& d1, const duration& d2) {
        return duration{d1.samples() + d2.samples()};
    }

    friend duration  operator-(const duration& d1, const duration& d2) {
        return duration{d1.samples() - d2.samples()};
    }

private:
    std::int64_t samples_;
};


// OSCILLATOR
struct oscillator {
    oscillator(float f)  { frequency(f); }

    void  frequency(float f) {
        m_ = std::exp(std::complex<float>{0.f, 2.f * pi * f * inv_frequency});
    }

    const std::complex<float>  phase()  { return phase_; }

    std::complex<float>  next() {
        phase_ *= m_;
        phase_ /= std::abs(phase_);
        return phase_;
    }

private:
    std::complex<float> phase_ {1.f, 0.f};
    std::complex<float> m_;
};


// SMOOTH
inline float smoothness_to_multiplier(float smoothness)
{
    if (smoothness == 0.f)  { return 1.f; }
    return -1 * std::expm1(-1 * inv_frequency / smoothness);
}

inline float multiplier_to_smoothness(float multiplier)
{
    if (multiplier == 1.f)  { return 0.f; }
    return -1 * inv_frequency / std::log1p(-1 * multiplier);
}

inline void smooth_update(float& value, float target_value, float smoothness_multiplier)
{
    value += (target_value - value) * smoothness_multiplier;
}


// RESAMPLER
struct resampler {
    resampler(float ratio = 1.f, float smoothness = 0.f);

    const float  ratio();
    float  ratio(float value);

    const float  smoothness();
    float  smoothness(float value);

    // ratio is target frequency / source frequency
    void  feed(std::span<const float> samples);

    const std::span<const float>  result()  { return result_; }

private:
    std::vector<float> result_;
    int position_ {0};
    float position_frac_ {0.f};

    float last_sample_[2] {0.f, 0.f};

    std::atomic<float> ratio_ {1.f};
    std::atomic<float> smoothness_multiplier_ {1.f};
    float real_ratio_ {1.f};

    void advance(float delta);
};


// STREAM
struct stream {
    // The length of the stream in samples, or nullopt if the stream is infinite
    virtual const std::optional<std::size_t>  length() = 0;

    // Return value less than sample count means end of stream
    // Must be called from mixing thread
    virtual std::size_t  read(float* data, std::size_t sample_count) = 0;  // TODO: pointer or reference?

    // The number of samples already played from this stream
    virtual const std::size_t  played() = 0;

    virtual  ~stream() {}
};

using stream_ptr = std::shared_ptr<stream>;


// STEREO
stream_ptr stereo(stream_ptr left, stream_ptr right);


// CHANNEL
struct channel {
    channel() = default;
    channel(stream_ptr stream) : stream_(std::move(stream))  {}

    const stream_ptr  stream()  { return std::atomic_load(&stream_); }
    stream_ptr  stream(stream_ptr new_stream)  { return std::atomic_exchange(&stream_, std::move(new_stream)); }

    stream_ptr  stop()  { return stream(nullptr); }
    const bool  is_stopped()  { return stream() != nullptr; }

private:
    stream_ptr stream_;
};

using channel_ptr = std::shared_ptr<channel>;


// MIXER
struct mixer : stream {
    virtual channel_ptr  add(stream_ptr stream) = 0;
};

using mixer_ptr = std::shared_ptr<mixer>;

mixer_ptr make_mixer();  // TODO


// TRACK
struct track {
    virtual const stream_ptr  stream() = 0;
    virtual const std::optional<std::size_t>  length() = 0;

    virtual  ~track()  {}  // TODO: = default?
};

using track_ptr = std::shared_ptr<track>;

// TODO
track_ptr load_raw(std::span<const float> data);
track_ptr load_raw(std::vector<float> data);

// TODO
track_ptr load_wav(std::span<const char> data);
track_ptr load_wav(const std::vector<char>& data);

// TODO
track_ptr load_mp3(std::span<const char> data);
track_ptr load_mp3(std::vector<char> data);


// RECORDER
struct recorder {
    virtual const std::optional<std::size_t>  length() = 0;
    virtual std::size_t  request(std::size_t samples) = 0;
    virtual const std::span<const float>  buffer() = 0;

    virtual  ~recorder() {}
};

std::shared_ptr<recorder> make_recorder(stream_ptr stream);
std::shared_ptr<recorder> make_recorder(std::vector<float> samples);
std::shared_ptr<recorder> make_recorder(std::span<const float> samples);


// DUPLICATE
track_ptr make_duplicator(std::shared_ptr<recorder> recorder);  // TODO

inline track_ptr make_duplicator(stream_ptr stream)
{
    return make_duplicator(make_recorder(std::move(stream)));
}

inline std::pair<stream_ptr, stream_ptr> duplicate(stream_ptr stream)
{
    auto track = make_duplicator(std::move(stream));
    return {track->stream(), track->stream()};
}


// ENGINE
struct engine {
    engine();
    ~engine();

    channel_ptr  output();

private:
    struct impl;
    std::unique_ptr<struct impl> pimpl_;
    struct impl& impl()  { return *pimpl_; }
    const struct impl& const impl()  { return *pimpl_; }
    template <typename ... Args> static auto make_impl(Args && ... args) {
        return std::make_unique<struct impl>(std::forward<Args>(args)...);
    }
};


