//
// Created by wright on 05/09/22.
//

#include <SDL_image.h>
#include "gui.h"
#include "../gfx/gfx.h"
#include "../disk/loadsave.h"

void GUI::initGUI() {
  SDL_Init(SDL_INIT_EVERYTHING);  // all of the above subsystems

  SDL_CreateWindowAndRenderer(SCREEN_SCALE * SCREEN_WIDTH, SCREEN_SCALE * SCREEN_HEIGHT, 0, &window, &renderer);
///   SDL_RenderSetScale(renderer, SCREEN_SCALE, SCREEN_SCALE);
  SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

  TTF_Init();  // TODO: move to Font class

  const char* fname = "/usr/share/fonts/liberation-mono/LiberationMono-Regular.ttf";
  ttf = TTF_OpenFont(fname, 16);
  if (ttf == NULL) {
    fprintf(stderr, "fonterr\n");
    exit(EXIT_FAILURE);
  }

  SDL_Color colorlist[16] = {Color::BLACK, Color::DKRED, Color::DKGREEN, Color::BROWN,
                             Color::DKBLUE, Color::BLACK, Color::DKCYAN, Color::GREY,
                             Color::DKGREY, Color::RED, Color::GREEN, Color::YELLOW,
                             Color::BLUE, Color::MAGENTA, Color::CYAN, Color::WHITE};

///   SDL_Palette* palette16 = SDL_AllocPalette(16);
///   SDL_SetPaletteColors(palette16, colorlist, 0, 16);

  SDL_SetRenderDrawColor(renderer, 0, 170, 0, 255);  // TODO: use a colorlist element
  SDL_RenderClear(renderer);

}

void GUI::createGUI(GameScreen screen) {
  std::vector<MenuChoice> choices;
  std::vector<std::string> choice_strings;

  const char* titleText = "Covert Action";

  SDL_Surface* textSurface;
  SDL_Texture* textTexture;
  SDL_Rect textRect;
  SDL_Rect xy;
  switch (screen) {
    case GameScreen::Building1:
    building_common:
      xy = {40, 120};
      createGUIMenu(buildMenu({"Place wiretap", "Break into building", "Watch the building", "Check Data", "Leave"}), Point(xy));
      break;
    case GameScreen::Building2:
      goto building_common;
    case GameScreen::Building3:
      goto building_common;
    case GameScreen::Building4:
      goto building_common;
    case GameScreen::Building5:
      goto building_common;
    case GameScreen::LoadSave:
      choice_strings = show_game_files();  // TODO-debug
      xy = {40, 120};
      createGUIMenu(choice_strings, Point(xy));
      // TODO: After user chooses an item: load_game(n); where n = <0..4>
      break;
    case GameScreen::Splash1:
      next_screen_tick = 2000 + SDL_GetTicks64();
      textSurface = TTF_RenderText(ttf, titleText, Color::WHITE, Color::DKGREEN);
      textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
      SDL_FreeSurface(textSurface);
      int w, h;
      TTF_SizeText(ttf, titleText, &w, &h);
      textRect.h = h;
      textRect.w = w;
      textRect.x = (SCREEN_WIDTH - w) >> 1;
      textRect.y = 5;
      SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
      SDL_DestroyTexture(textTexture);
      SDL_RenderPresent(renderer);
      break;
    case GameScreen::CIAData:
      xy = {40, 120};
      createGUIMenu(buildMenu(
          {"Review Clues", "Review Suspects", "Inside Information", "News Bulletins", "Organization Summary",
           "City Summary", "Activity Reports"}), xy);
      break;
    case GameScreen::CIAIntel:
      xy = {40, 120};
      createGUIMenu(
          buildMenu({"Local Scan", "International Scan", "Active Wire Taps", "Accuse Double Agent", "Check with Sam"}), xy);
      break;

      /* UNUSED CASES */
    case GameScreen::Splash2:
    case GameScreen::CityMainMenu:
    case GameScreen::Chief:
    case GameScreen::CIAMain:
    case GameScreen::CIASam:
    case GameScreen::CIACrypto:
    case GameScreen::CombatArrest:
    case GameScreen::CombatRecover:
    case GameScreen::CombatCaptive:
    case GameScreen::Hotel:
    case GameScreen::ReviewClues:
    case GameScreen::ReviewSuspects:
    case GameScreen::ReviewInsideInfo:
    case GameScreen::ReviewNews:
    case GameScreen::ReviewOrg:
    case GameScreen::ReviewCity:
    case GameScreen::ReviewActivity:
    case GameScreen::Typewriter:
    case GameScreen::GameExit:
    default:
      /// throw std::runtime_error("unhandled game screen");
      exit(EXIT_FAILURE);
      break;
  }
}

void GUI::createGUIMenu(std::vector<std::string> choice_strings, Point pt) {
  for (auto& choice : choice_strings) {
    createGUIText(choice, pt++);
  }
}

void GUI::createGUIMenu(const std::vector<MenuChoice> choices, Point pt) {
  for (auto& choice : choices) {
    createGUIText(choice.txt, pt++);
  }
}

void GUI::createGUIText(const std::string txt, Point dstRect) {
  SDL_RectEmpty(&dstRect.dstRect);

  uint32_t flags = 0;
  int w = 0;
  int h = 0;
  int d = 0;
  uint32_t fmt = 0;

  SDL_Surface* txtSurface = SDL_CreateRGBSurfaceWithFormat(flags, w, h, d, fmt);
  SDL_Texture* txtTexture = SDL_CreateTextureFromSurface(renderer, txtSurface);
  SDL_FreeSurface(txtSurface);
  SDL_RenderCopy(renderer, txtTexture, nullptr, &dstRect.dstRect);
}