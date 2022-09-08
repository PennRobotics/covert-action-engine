#ifndef SPNA_GAME_LOADSAVE_H
#define SPNA_GAME_LOADSAVE_H

#include <iostream>  // TODO-debug
#include <stdexcept>
#include <string>  // TODO-debug
#include <vector>

#include <SDL.h>

enum class FileStatus : int {
    Ok = 0,
    NotFound = 1,
};

std::vector<std::string> show_game_files();

FileStatus load_game(int game_idx);

int save_game(const char* fname);

#endif //SPNA_GAME_LOADSAVE_H
