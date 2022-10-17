#pragma once

#include <psemek/audio/stream.hpp>

namespace psemek::audio
{

	stream_ptr loop(stream_ptr stream, std::optional<std::size_t> count = {});

}
