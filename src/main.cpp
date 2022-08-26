#include <SDL.h>

#include <memory>

#include "types.h"

#include "combat.h"
#include "driving.h"
#include "cryptography.h"
#include "electronics.h"
#include "menu.h"

/*
 * TODO:
 * - Main character statistics
 *   - Global Difficulty, Skill Modifiers
 *   - Character Level
 * - Room Generation (Combat)
 *   - Bug details
 *   - Password chart
 *   - Modification for ambush, break-out, etc.
 * - HQ
 *   - Intelligence Menu
 *   - Surveillance
 *   - Clues
 *   - Activity reports
 *   - Agent states
 * - Populate all possible messages (or generative phrases)
 * - Hotel
 *   - Gossip
 * - Building Exteriors
 * - Clock
 * - Airport
 *   - World map
 * - Mission
 *   - Participant organizational chart
 *   - Debrief
 *   - Scoring
 *   - Loading from data files
 *   - Save / Load functionality?
 * - User Interface
 *   - Menus, easily implemented
 *   - Graphics / Picture display / Fonts
 *   - Sound
 *   - Input devices
 * - Error Handling
 * - Cross-Platform
 * -   ... and much, much more!
 */

// TODO: enforce variable casing
// TODO: style guide
// TODO: consistency in spec (unique_ptr vs new)



static std::unique_ptr<MiniGameCombat> mGameCombat;
static std::unique_ptr<MiniGameDriving> mGameDriving;
static std::unique_ptr<MiniGameCryptography> mGameCrypto;
static std::unique_ptr<MiniGameElectronics> mGameElec;

typedef bool ScreenTODO;  // TODO
typedef bool ScreenHotel;
typedef bool ScreenMainMenu;
static std::unique_ptr<ScreenMainMenu> scMainMenu;  /* added later */
static std::unique_ptr<ScreenTODO> scTypewriter;
static std::unique_ptr<ScreenHotel> scHotel;
static std::unique_ptr<ScreenTODO> scChief;
static std::unique_ptr<ScreenTODO> scHQ;
static std::unique_ptr<ScreenTODO> scHQData;
static std::unique_ptr<ScreenTODO> scHQIntel;
static std::unique_ptr<ScreenTODO> scHQCrypto;
static std::unique_ptr<ScreenTODO> scBuilding;
static std::unique_ptr<ScreenTODO> scChooseCombat;
static std::unique_ptr<ScreenTODO> scChooseDriving;

// TODO
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200

int main()
{
  SDL_Window* window = NULL;
  SDL_Surface* screen_surface = NULL;

///   SDL_Init(SDL_INIT_TIMER);  // timer subsystem
  SDL_Init(SDL_INIT_AUDIO);  // audio subsystem
///   SDL_Init(SDL_INIT_VIDEO);  // video subsystem; automatically initializes the events subsystem
///   SDL_Init(SDL_INIT_JOYSTICK);  // joystick subsystem; automatically initializes the events subsystem
///   SDL_Init(SDL_INIT_HAPTIC);  // haptic (force feedback) subsystem
///   SDL_Init(SDL_INIT_GAMECONTROLLER);  // controller subsystem; automatically initializes the joystick subsystem
///   SDL_Init(SDL_INIT_EVENTS);  // events subsystem
///   SDL_Init(SDL_INIT_EVERYTHING);  // all of the above subsystems
///   SDL_Init(SDL_INIT_NOPARACHUTE);  // compatibility; this flag is ignored

  goto eject;

  std::cout << SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) << "\n";
  //std::cout << TTF_Init() << "\n";
  window = SDL_CreateWindow("UP", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  screen_surface = SDL_GetWindowSurface(window);

  SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0xEF, 0xFF, 0xEF));
  SDL_UpdateWindowSurface(window);

  // TODO: audio, resources, etc.

eject:
  SDL_Delay(4000);

  SDL_DestroyWindow(window);

  // for(;;){}
  //TTF_Quit();
  SDL_Quit();

  /*
  mGameCombat = std::make_unique<MiniGameCombat>();
  mGameDriving = std::make_unique<MiniGameDriving>();
  mGameCrypto = std::make_unique<MiniGameCryptography>();
  mGameElec = std::make_unique<MiniGameElectronics>();

  mGameCombat->start(difficulty::LEVEL2);
  mGameDriving->start(difficulty::LEVEL2);
  mGameCrypto->start(difficulty::LEVEL2);
  mGameElec->start(difficulty::LEVEL2);
  */

  return 0;
}

