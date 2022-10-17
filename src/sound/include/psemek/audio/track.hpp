#pragma once

#include <psemek/audio/stream.hpp>
#include <psemek/util/span.hpp>

#include <optional>
#include <vector>

namespace psemek::audio
{

	struct track
	{
		virtual stream_ptr stream() const = 0;
		virtual std::optional<std::size_t> length() const = 0;

		virtual ~track(){}
	};

	using track_ptr = std::shared_ptr<track>;

	track_ptr load_raw(util::span<float const> data);
	track_ptr load_raw(std::vector<float> data);

	track_ptr load_wav(util::span<char const> data);
	track_ptr load_wav(std::vector<char> const & data);

	track_ptr load_mp3(util::span<char const> data);
	track_ptr load_mp3(std::vector<char> data);

}
