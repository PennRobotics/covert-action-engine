#include <psemek/audio/resampler.hpp>
#include <psemek/audio/smooth.hpp>
#include <psemek/geom/math.hpp>

#include <psemek/log/log.hpp>

#include <vector>

namespace psemek::audio
{

	resampler::resampler(float ratio, float smoothness)
		: ratio_(ratio)
		, smoothness_multiplier_(smoothness_to_multiplier(smoothness))
		, real_ratio_(ratio)
	{}

	float resampler::ratio() const
	{
		return ratio_.load();
	}

	float resampler::ratio(float value)
	{
		return ratio_.exchange(value);
	}

	float resampler::smoothness() const
	{
		return multiplier_to_smoothness(smoothness_multiplier_.load());
	}

	float resampler::smoothness(float value)
	{
		return multiplier_to_smoothness(smoothness_multiplier_.exchange(smoothness_to_multiplier(value)));
	}

	void resampler::feed(util::span<float const> samples)
	{
		result_.clear();

		if (samples.empty())
			return;

		float const ratio = ratio_.load();
		float const smoothness_multiplier = smoothness_multiplier_.load();

		while (position_ < 0)
		{
			result_.push_back(geom::lerp(last_sample_[0], samples[0], position_frac_));
			result_.push_back(geom::lerp(last_sample_[1], samples[1], position_frac_));
			real_ratio_ += (ratio - real_ratio_) * smoothness_multiplier;
			advance(1.f / real_ratio_);
		}

		while (2 * position_ + 3 < samples.size())
		{
			result_.push_back(geom::lerp(samples[2 * position_ + 0], samples[2 * position_ + 2], position_frac_));
			result_.push_back(geom::lerp(samples[2 * position_ + 1], samples[2 * position_ + 3], position_frac_));
			real_ratio_ += (ratio - real_ratio_) * smoothness_multiplier;
			advance(1.f / real_ratio_);
		}

		position_ -= static_cast<int>(samples.size()) / 2;

		last_sample_[0] = samples[samples.size() - 2];
		last_sample_[1] = samples[samples.size() - 1];
	}

	void resampler::advance(float delta)
	{
		position_frac_ += delta;
		auto floor = static_cast<int>(std::floor(position_frac_));
		position_ += floor;
		position_frac_ -= floor;
	}

}
