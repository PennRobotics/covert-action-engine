// TODO: Anything at all non-graphics related needs to be in a ui.h. GUI should only be the graphics components of UI. This would allow a console-only mode.

#include "gui.h"

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

static const SDL_Color colors[] = {
    CAColor::BLACK, CAColor::DKRED, CAColor::DKGREEN, CAColor::BROWN,
    CAColor::DKBLUE, CAColor::BLACK, CAColor::DKCYAN, CAColor::GREY,
    CAColor::DKGREY, CAColor::RED, CAColor::GREEN, CAColor::YELLOW,
    CAColor::BLUE, CAColor::MAGENTA, CAColor::CYAN, CAColor::WHITE
};


void GUI::initGUI()
{
  SDL_CreateWindowAndRenderer(SCREEN_SCALE * SCREEN_WIDTH, SCREEN_SCALE * SCREEN_HEIGHT, 0, &window, &renderer);
  SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

  TTF_Init();  // TODO: move to Font class

// TODO
  const char* fname = "/usr/share/fonts/liberation-mono/LiberationMono-Regular.ttf";
//  const char* fname = "C:\\Windows\\Fonts\\LiberationMono-Regular.ttf";
  ttf = TTF_OpenFont(fname, 8);
  if (ttf == NULL) {
    fprintf(stderr, "fonterr\n");
    exit(EXIT_FAILURE);
  }

  SDL_Palette* palette16 = SDL_AllocPalette(16);
  SDL_SetPaletteColors(palette16, colors, 0, 16);  // TODO: figure this out
}


void GUI::setBGColor(const SDL_Color c)
{
  SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);  // TODO: use a colorlist element
  SDL_RenderClear(renderer);
}


void GUI::fillBox(const SDL_Color c, const SDL_Rect r)
{
  SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(renderer, &r);
}


void GUI::drawBox(const SDL_Color c, const SDL_Rect r)
{
  SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, SDL_ALPHA_OPAQUE);
  SDL_RenderDrawRect(renderer, &r);
}


void GUI::drawText(const SDL_Color c, const char* txt, const SDL_Point pt)
{
  int w, h;
  SDL_Surface* textSurface;
  SDL_Texture* textTexture;
  SDL_Rect textRect;

  textSurface = TTF_RenderText_Solid(ttf, txt, c);
  textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
  SDL_FreeSurface(textSurface);
  TTF_SizeText(ttf, txt, &w, &h);
  textRect.h = h;
  textRect.w = w;
  textRect.x = pt.x;
  textRect.y = pt.y;
  SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
  SDL_DestroyTexture(textTexture);
}


void GUI::centerText(const SDL_Color c, const char* txt, const int y)
{
  int w;
  TTF_SizeText(ttf, txt, &w, nullptr);
  drawText(c, txt, SDL_Point((SCREEN_WIDTH - w) >> 1, y));
}


bool GUI::guiShouldRefresh()  { return dialogType == DialogType::INFOTIMER && SDL_GetTicks64() >= next_screen_tick; }


void GUI::createGUI(GameScreen screen)
{
  switch (screen) {
    case GameScreen::Building1:
    building_common:
///       createGUIMenu(buildMenu({"Place wiretap", "Break into building", "Watch the building", "Check Data", "Leave"}), SDL_Point(xy));
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
///       createGUIMenu(choice_strings, SDL_Point(xy));
      // TODO: After user chooses an item: load_game(n); where n = <0..4>
      break;
    case GameScreen::Splash1:
      setBGColor(CAColor::GREEN);
      next_screen_tick = 200 + SDL_GetTicks64();
      centerText(CAColor::WHITE, "Covert Action", 5);
      break;
    case GameScreen::Splash2:
      setBGColor(CAColor::BLUE);
      next_screen_tick = 200 + SDL_GetTicks64();
      centerText(CAColor::WHITE, "Credits", 5);
      break;
    case GameScreen::BeginMenu:
      setBGColor(CAColor::BLACK);
#ifdef PLACEHOLDERS
      _imagePlaceholder(15, 5, 20, 15);
#endif
      dialogType = DialogType::MINIMENU;
      drawBox(CAColor::WHITE, SDL_Rect(97, 76, 125, 46));
      drawText(CAColor::WHITE, "Do you want to...", SDL_Point(102, 80));
      if (currentMenu.empty()) {
        currentMenu = buildMenu({" Create a New Character", " Load a Saved Game", " Practice a skill", " Review Hall of Fame"});
      }
      updateGUIMenu(currentMenu, SDL_Rect(102, 88, 115, 1));
      // TODO: Create menu
      break;
    case GameScreen::NewCharacter:
      dialogType = DialogType::TEXTENTRY;
      setBGColor(CAColor::RED);
      SDL_RenderPresent(renderer);
      SDL_Delay(1000);
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
///       createGUIMenu(buildMenu(
///           {"Review Clues", "Review Suspects", "Inside Information", "News Bulletins", "Organization Summary",
///            "City Summary", "Activity Reports"}), xy);
      break;
    case GameScreen::CIAIntel:
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
  SDL_RenderPresent(renderer);
}


// TODO: remove if unused
void GUI::createGUIMenu(std::vector<std::string> choice_strings, const SDL_Rect r0)
{
  SDL_Point pt { r0.x , r0.y };
  int i = 0;
  for (auto& choice : choice_strings) {
    if (i == 0) {
      fillBox(CAColor::YELLOW, SDL_Rect(pt.x, pt.y, r0.w, 8));
    }
    drawText(CAColor::GREY, choice.c_str(), pt);
    pt.y += 8;
    i++;
  }
}


void GUI::updateGUIMenu(const std::vector<MenuChoice> choices, SDL_Rect r0)
{
  SDL_Point pt { r0.x , r0.y };
  for (auto& choice : choices) {
    if (choice.selected) {
      fillBox(CAColor::YELLOW, SDL_Rect(pt.x, pt.y, r0.w, 8));
    }
    drawText(CAColor::GREY, choice.txt.c_str(), pt);
    pt.y += 8;
  }
}


void GUI::chooseMenuPrev()
{
  for (auto& choice : currentMenu) {
    if (choice.selected) {
      choice.selected = false;
      choice.prev->selected = true;
      return;
    }
  }
}


void GUI::chooseMenuNext()
{
  for (auto& choice : currentMenu) {
    if (choice.selected) {
      choice.selected = false;
      choice.next->selected = true;
      return;
    }
  }
}


void GUI::selectMenuState()
{
  for (auto& choice : currentMenu) {
    if (choice.selected) {
      selectedChoice = choice.id;
      return;
    }
  }
}


void GUI::selectMenuDefault()
{
  selectedChoice = 0;
}



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
