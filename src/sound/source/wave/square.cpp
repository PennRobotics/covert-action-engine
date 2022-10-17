#include <psemek/audio/wave/square.hpp>
#include <psemek/audio/wave/generator.hpp>
#include <psemek/audio/oscillator.hpp>

#include <cmath>

namespace psemek::audio
{

	stream_ptr square_wave(float frequency)
	{
		auto func = [o = oscillator{frequency}]() mutable {
			return o.next().imag() > 0.f ? 1.f : -1.f;
		};

		return make_generator(func);
	}

}
