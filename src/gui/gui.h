#pragma once

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200
#define SCREEN_SCALE 5

#include <array>
/// #include <string>
#include <vector>
#include <memory>

#ifndef NO_SDL
#include <SDL_ttf.h>
#else
typedef struct SDL_Rect  { int x,y,w,h; }  SDL_Rect;
typedef struct SDL_Point  { int x,y; }  SDL_Point;
#endif

#include "../gfx/gfx.h"
/// #include "../disk/loadsave.h"
#include "../types.h"
/// #include "point.h"
#include "menu.h"

/// #include "../gameplay/gamestate.h"


class GUI {
public:
    GUI() = default;
    ~GUI() = default;
    GUI(const GUI&) = delete;
    GUI& operator=(const GUI&) = delete;
    void initGUI();
    void createGUI(GameScreen screen);
    void createGUIMenu(std::vector<std::string> choice_strings, SDL_Rect r0);
    void updateGUIMenu(std::vector<MenuChoice> choices, SDL_Rect r0);
    void setBGColor(const SDL_Color c);
    void fillBox(const SDL_Color c, const SDL_Rect r);
    void drawBox(const SDL_Color c, const SDL_Rect r);
    void drawText(const SDL_Color c, const char* txt, const SDL_Point pt);
    void centerText(const SDL_Color c, const char* txt, const int y);
    void chooseMenuPrev();
    void chooseMenuNext();
    void selectMenuState();
    void selectMenuDefault();
    void displayFrame();
    bool guiShouldRefresh();
#ifdef PLACEHOLDERS
    void _imagePlaceholder(const int&, const int&, const int&, const int&);
#endif
///   void /*TODO*/choiceS  electionCallback()  { NULL; }
/// protected:
#ifndef NO_SDL
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* screen_surface = nullptr;
    TTF_Font* ttf;
    Uint64 next_screen_tick;
#else
	uint64_t next_screen_tick;  // TODO
#endif
///   /* TODO: surfaces and textures and etc. */
/// private:
    std::vector<MenuChoice> currentMenu;
    int selectedChoice;
    DialogType dialogType { DialogType::INFOTIMER };
};
