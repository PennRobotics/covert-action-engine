#pragma once

#include <string>  // TODO-debug
#include <vector>

enum class FileStatus : int {
    Ok = 0,
    NotFound = 1,
};

std::vector<std::string> show_game_files();

FileStatus load_game(int game_idx);

int save_game(const char* fname);
