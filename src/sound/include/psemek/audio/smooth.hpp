#pragma once

#include <psemek/audio/constants.hpp>

#include <cmath>

namespace psemek::audio
{

	inline float smoothness_to_multiplier(float smoothness)
	{
		if (smoothness == 0.f)
			return 1.f;
		return - std::expm1(- inv_frequency / smoothness);
	}

	inline float multiplier_to_smoothness(float multiplier)
	{
		if (multiplier == 1.f)
			return 0.f;

		return - inv_frequency / std::log1p(- multiplier);
	}

	inline void smooth_update(float & value, float target_value, float smoothness_multiplier)
	{
		value += (target_value - value) * smoothness_multiplier;
	}

}
