#ifndef CA_GUI_H
#define CA_GUI_H

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200
#define SCREEN_SCALE 5

#include <array>
/// #include <string>
#include <vector>
#include <memory>

#include <SDL_ttf.h>

#include "../gfx/gfx.h"
/// #include "../disk/loadsave.h"
#include "../types.h"
/// #include "point.h"
/// #include "menu.h"

/// #include "../gameplay/gamestate.h"

class GUI {
public:
    GUI() = default;
    ~GUI() = default;
    GUI(const GUI&) = delete;
    GUI& operator=(const GUI&) = delete;
    void initGUI();
    void createGUI(GameScreen screen);
///     void createGUIMenu(std::vector<std::string> choice_strings, Point pt);
///     void createGUIMenu(std::vector<MenuChoice> choices, Point pt);
///     void createGUIText(std::string txt, Point pt);
    void setBGColor(SDL_Color c);
    void updateGUI();
    void displayFrame();
    bool refreshNow();
///   void /*TODO*/choiceS  electionCallback()  { NULL; }
/// protected:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer;
    SDL_Surface* screen_surface = nullptr;
///   /* TODO: surfaces and textures and etc. */
/// private:
    TTF_Font* ttf;
    Uint64 next_screen_tick;
    DialogType dialogType { DialogType::INFOTIMER };
};



#endif
