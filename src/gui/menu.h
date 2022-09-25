#pragma once

#include <string>
#include <vector>

/* TODO: add menu defs, font, keyboard handler, anims, etc. */

struct MenuChoice {
    int id;
    bool selected;
    std::string txt;
    MenuChoice* prev;
    MenuChoice* next;
};

std::vector<MenuChoice> buildMenu(std::vector<std::string> choice_strings);
