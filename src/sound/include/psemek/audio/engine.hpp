#pragma once

#include <psemek/audio/stream.hpp>
#include <psemek/audio/track.hpp>
#include <psemek/audio/channel.hpp>

#include <psemek/util/pimpl.hpp>
#include <psemek/util/span.hpp>

#include <psemek/io/stream.hpp>

#include <memory>
#include <string_view>
#include <vector>

namespace psemek::audio
{

	struct engine
	{
		engine();
		~engine();

		channel_ptr output();

	private:
		psemek_declare_pimpl
	};

}
