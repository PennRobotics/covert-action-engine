// TODO: Anything at all non-graphics related needs to be in a ui.h. GUI should only be the graphics components of UI. This would allow a console-only mode.

/// #define SDL_MAIN_HANDLED
/// #include <SDL_image.h>
#include "gui.h"

/// extern std::unique_ptr<GameState> gameState;
std::unique_ptr<GUI> gui;

namespace CAColor {
    SDL_Color BLACK = { 0x00, 0x00, 0x00 };
    SDL_Color DKRED = { 0xAA, 0x00, 0x00 };
    SDL_Color DKGREEN = { 0x00, 0xAA, 0x00 };
    SDL_Color BROWN = { 0xAA, 0x55, 0x00 };
    SDL_Color DKBLUE = { 0x00, 0x00, 0xAA };
    SDL_Color UNK = { 0x00, 0x00, 0x00 };
    SDL_Color DKCYAN = { 0x00, 0xAA, 0xAA };
    SDL_Color GREY = { 0xAA, 0xAA, 0xAA };
    SDL_Color DKGREY = { 0x55, 0x55, 0x55 };
    SDL_Color RED = { 0xFF, 0x55, 0x55 };
    SDL_Color GREEN = { 0x55, 0xFF, 0x55 };
    SDL_Color YELLOW = { 0xFF, 0xFF, 0x55 };
    SDL_Color BLUE = { 0x55, 0x55, 0xFF };
    SDL_Color MAGENTA = { 0xFF, 0x55, 0xFF };
    SDL_Color CYAN = { 0x55, 0xFF, 0xFF };
    SDL_Color WHITE = { 0xFF, 0xFF, 0xFF };
}

static const std::array<SDL_Color, 16> colors = {
    CAColor::BLACK, CAColor::DKRED, CAColor::DKGREEN, CAColor::BROWN,
    CAColor::DKBLUE, CAColor::BLACK, CAColor::DKCYAN, CAColor::GREY,
    CAColor::DKGREY, CAColor::RED, CAColor::GREEN, CAColor::YELLOW,
    CAColor::BLUE, CAColor::MAGENTA, CAColor::CYAN, CAColor::WHITE };


void GUI::initGUI() {
///   SDL_Init(SDL_INIT_EVERYTHING);  // all of the above subsystems

  SDL_CreateWindowAndRenderer(SCREEN_SCALE * SCREEN_WIDTH, SCREEN_SCALE * SCREEN_HEIGHT, 0, &window, &renderer);
///   SDL_RenderSetScale(renderer, SCREEN_SCALE, SCREEN_SCALE);
  SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

  TTF_Init();  // TODO: move to Font class

//* TODO-debug
  const char* fname = "/usr/share/fonts/liberation-mono/LiberationMono-Regular.ttf";
//  const char* fname = "C:\\Windows\\Fonts\\LiberationMono-Regular.ttf";
  ttf = TTF_OpenFont(fname, 16);
  if (ttf == NULL) {
    fprintf(stderr, "fonterr\n");
    exit(EXIT_FAILURE);
  }
// */

  /*
// */

///   SDL_Palette* palette16 = SDL_AllocPalette(16);
///   SDL_SetPaletteColors(palette16, colorlist, 0, 16);


}

void GUI::setBGColor(SDL_Color c) {
  SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);  // TODO: use a colorlist element
  SDL_RenderClear(renderer);
}


bool GUI::guiShouldRefresh()  { return dialogType == DialogType::INFOTIMER && SDL_GetTicks64() >= next_screen_tick; }


void GUI::createGUI(GameScreen screen) {
///   std::vector<MenuChoice> choices;
  std::vector<std::string> choice_strings;

  const char* titleText = "Covert Action";
  const char* titleTextB = "Credits";
  int w, h;

  SDL_Surface* textSurface;
  SDL_Texture* textTexture;
  SDL_Rect textRect;
  SDL_Rect xy;
  switch (screen) {
    case GameScreen::Building1:
    building_common:
      xy = {40, 120};
///       createGUIMenu(buildMenu({"Place wiretap", "Break into building", "Watch the building", "Check Data", "Leave"}), Point(xy));
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
///       choice_strings = show_game_files();  // TODO-debug
      xy = {40, 120};
///       createGUIMenu(choice_strings, Point(xy));
      // TODO: After user chooses an item: load_game(n); where n = <0..4>
      break;
    case GameScreen::Splash1:
      setBGColor(CAColor::GREEN);
      next_screen_tick = 2000 + SDL_GetTicks64();
      textSurface = TTF_RenderText_Solid(ttf, titleText, CAColor::WHITE);
      textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
      SDL_FreeSurface(textSurface);
      TTF_SizeText(ttf, titleText, &w, &h);
      textRect.h = h;
      textRect.w = w;
      textRect.x = (SCREEN_WIDTH - w) >> 1;
      textRect.y = 5;
      SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
      SDL_DestroyTexture(textTexture);
      SDL_RenderPresent(renderer);
      break;
    case GameScreen::Splash2:
      setBGColor(CAColor::BLUE);
      next_screen_tick = 2000 + SDL_GetTicks64();
      textSurface = TTF_RenderText_Solid(ttf, titleTextB, CAColor::WHITE);
      textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
      SDL_FreeSurface(textSurface);
      TTF_SizeText(ttf, titleTextB, &w, &h);
      textRect.h = h;
      textRect.w = w;
      textRect.x = (SCREEN_WIDTH - w) >> 1;
      textRect.y = 5;
      SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
      SDL_DestroyTexture(textTexture);
      SDL_RenderPresent(renderer);
      break;
    case GameScreen::BeginMenu:
      dialogType = DialogType::MINIMENU;
      // TODO: Create menu
      break;
    case GameScreen::NewCharacter:
      dialogType = DialogType::TEXTENTRY;
      break;
    case GameScreen::SkillUpgrade:
      dialogType = DialogType::SKILLSELECT;
      break;
    case GameScreen::Load:
      dialogType = DialogType::MENU;
      break;
    case GameScreen::SkillPractice:
      dialogType = DialogType::MINIMENU;
      break;
    case GameScreen::HallOfFame:
      dialogType = DialogType::INFO;
      break;
    case GameScreen::CIAData:
      xy = {40, 120};
///       createGUIMenu(buildMenu(
///           {"Review Clues", "Review Suspects", "Inside Information", "News Bulletins", "Organization Summary",
///            "City Summary", "Activity Reports"}), xy);
      break;
    case GameScreen::CIAIntel:
      xy = {40, 120};
///       createGUIMenu(
///           buildMenu({"Local Scan", "International Scan", "Active Wire Taps", "Accuse Double Agent", "Check with Sam"}), xy);
      break;

      /* UNUSED CASES */
    case GameScreen::Chief:
    case GameScreen::MastermindLineup:
    case GameScreen::ShowNewClues:
    case GameScreen::CIAContact:
    case GameScreen::CIAMainMenu:
    case GameScreen::CIASam:
    case GameScreen::CIACrypto:
    case GameScreen::CityMainMenu:
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

/*
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
// */

#ifdef PLACEHOLDERS
#include <iostream>
const unsigned char singlepixel_bmp[] = {
  0x42, 0x4d, 0x8e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x00,
  0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
  0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x23, 0x2e, 0x00, 0x00, 0x23, 0x2e, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff,
  0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x47,
  0x52, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x98, 0xf8, 0x00
};

void GUI::_imagePlaceholder(const int& x, const int& y, const int& w, const int& h)
{
  SDL_Surface* ss = SDL_GetWindowSurface(window);
  SDL_Rect pxRect { x, y, w, h };
  SDL_RWops* pxIO = SDL_RWFromConstMem(singlepixel_bmp, sizeof(singlepixel_bmp));
  SDL_Surface* pxSurf = SDL_LoadBMP_RW(pxIO, 1);
  SDL_Texture* pxTex = SDL_CreateTextureFromSurface(renderer, pxSurf);
  SDL_FreeSurface(pxSurf);
  SDL_RenderCopy(renderer, pxTex, nullptr, &pxRect);
  SDL_DestroyTexture(pxTex);
  SDL_RenderPresent(renderer);
}
#endif
