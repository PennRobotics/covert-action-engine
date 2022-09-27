#include "loadsave.h"

#ifndef NO_SDL
#include <SDL.h>
#endif

#include <stdexcept>

#define SAVE_FILE_LIST {"CV0.SVE", "CV1.SVE", "CV2.SVE", "CV3.SVE", "CV4.SVE"}

std::vector<std::string> show_game_files() {
// TODO
#ifndef NO_SDL
    SDL_RWops* reader;
    std::vector<std::string> game_names;
    std::string game_name;
    char* callsign = (char*)malloc(12);  // TODO: max size? safer data structure?
    for (auto& fname : SAVE_FILE_LIST) {
        reader = SDL_RWFromFile(fname, "rb");
        if (reader != nullptr) {
            // Show name, probably at offset 0x46A
            SDL_RWseek(reader, 0x46A, RW_SEEK_SET);
            SDL_RWread(reader, callsign, 11, 1);  // TODO: max size?
            SDL_RWclose(reader);
        } else {
            // Name is empty
            memcpy(callsign, " - Empty -", 11);
        }
        game_name = callsign;
        game_names.push_back(game_name);
    }
    return game_names;
#else
	return std::vector<std::string>{"A", "B", "C", "D"};
#endif
}

// TODO
#ifndef NO_SDL
FileStatus load_game(int game_idx) {
    int i = 0;
    char* fname = (char*)malloc(7);
    for (auto& fname_candidate : SAVE_FILE_LIST) {
        if (i == game_idx)  { fname = (char*)fname_candidate;}
        i++;
    }
    SDL_RWops* reader;
    reader = SDL_RWFromFile(fname, "rb");
    if (reader == nullptr) {
        // Save file does not exist
///         std::cout << fname << std::endl;
        return FileStatus::NotFound;
    }
    SDL_RWclose(reader);
    return FileStatus::Ok;
}

int save_game(const char* fname) {
    SDL_RWops* reader;
    reader = SDL_RWFromFile(fname, "rb");
    if (reader == nullptr) {
        // File does not yet exist, create fresh data for new file.

        // TODO

    } else {
        // Import existing save file, modify

        // TODO

        SDL_RWclose(reader);
    }

    SDL_RWops* writer;
    writer = SDL_RWFromFile(fname, "wb");
    if (writer == nullptr) {
        throw std::runtime_error("cannot write to save game file");
    } else {
        SDL_RWwrite(writer, "abcde", 6, 1);
    }
    return 0;
}
#endif
