#include <string>
#include <vector>
#include "menu.h"

std::vector<MenuChoice> buildMenu(std::vector<std::string> choice_strings) {
    std::vector<MenuChoice> menu_constructor;
    MenuChoice this_menu_choice;

    int id = 0;
    for (auto& choicestring : choice_strings) {
        this_menu_choice.id = id;
        this_menu_choice.txt = std::move(choicestring);
        this_menu_choice.prev = (id > 0) ? &menu_constructor[id - 1] : nullptr;
        this_menu_choice.next = nullptr;

        menu_constructor.push_back(this_menu_choice);
        id++;
    }

    for (int i = 1; i < id; i++) {
        menu_constructor[i-1].next = &menu_constructor[i];
    }

    return menu_constructor;
}