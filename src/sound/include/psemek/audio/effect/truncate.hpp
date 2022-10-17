#pragma once

#include <psemek/audio/stream.hpp>
#include <psemek/audio/duration.hpp>

namespace psemek::audio
{

	stream_ptr truncate(stream_ptr stream, duration length);

}
