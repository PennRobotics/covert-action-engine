#pragma once

#include <string>
#include <vector>

/* TODO: add menu defs, font, keyboard handler, anims, etc. */

struct MenuChoice {
    MenuChoice* prev;
    MenuChoice* next;
    int id;
    std::string txt;
};

std::vector<MenuChoice> buildMenu(std::vector<std::string> choice_strings);
