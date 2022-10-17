#include <psemek/audio/track.hpp>
#include <psemek/audio/duplicate.hpp>

namespace psemek::audio
{

	track_ptr load_raw(util::span<float const> data)
	{
		return make_duplicator(make_recorder(data));
	}

	track_ptr load_raw(std::vector<float> data)
	{
		return make_duplicator(make_recorder(std::move(data)));
	}

}
