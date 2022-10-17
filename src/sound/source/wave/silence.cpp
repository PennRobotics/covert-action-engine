#include <psemek/audio/wave/silence.hpp>
#include <psemek/audio/wave/generator.hpp>

namespace psemek::audio
{

	stream_ptr silence()
	{
		return make_generator([]{ return 0.f; });
	}

}
