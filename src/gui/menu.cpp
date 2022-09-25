#include "menu.h"

std::vector<MenuChoice> buildMenu(std::vector<std::string> choice_strings) {
    std::vector<MenuChoice> menu_constructor;
    MenuChoice this_menu_choice;

    int idx = 0;
    for (auto& choicestring : choice_strings) {
        this_menu_choice.id = idx + 1;
        this_menu_choice.txt = std::move(choicestring);
        this_menu_choice.selected = !idx;  // First choice selected by default

        menu_constructor.push_back(this_menu_choice);
        idx++;
    }

    menu_constructor[0].prev = &menu_constructor[0];
    for (int i = idx - 1; i > 0; i--) {
        menu_constructor[i].prev = &menu_constructor[i - 1];
    }

    menu_constructor[idx - 1].next = &menu_constructor[idx - 1];
    for (int i = 1; i < idx; i++) {
        menu_constructor[i - 1].next = &menu_constructor[i];
    }

    return menu_constructor;
}
