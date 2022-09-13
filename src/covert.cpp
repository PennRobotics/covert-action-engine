#define SDL_MAIN_HANDLED
#include <SDL_stdinc.h>

#include <SDL.h>
/// #include <SDL_ttf.h>
/// #include <SDL_mixer.h>
/// #include <SDL_image.h>

extern int case_gen();

#include "covert.h"


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
 *   - Graphics / Picture display / Fonts / # colors
 *   - Sound
 *   - Input devices
 * - Error Handling
 * - Cross-Platform
 * -   ... and much, much more!
 */

// TODO: enforce variable casing
// TODO: style guide
// TODO: consistency in spec (unique_ptr vs new)


/// #include "minigame/combat.h"
/// #include "minigame/cryptography.h"
/// #include "minigame/driving.h"
/// #include "minigame/electronics.h"

// TODO
std::unique_ptr<MainChar> mainChar;
std::unique_ptr<GUI> gui;
std::unique_ptr<GameState> gameState;

/// MiniGameCombat& miniGameCombat()  { static MiniGameCombat mg {}; return mg; }
/// MiniGameCryptography& miniGameCrypto()  { static MiniGameCryptography mg {}; return mg; }
/// MiniGameDriving& miniGameDriving()  { static MiniGameDriving mg {}; return mg; }
/// MiniGameElectronics& miniGameElec()  { static MiniGameElectronics mg {}; return mg; }



#include "minigame/combat.h"
int do_covert()
{
  mainChar = std::make_unique<MainChar>();

  gameState = std::make_unique<GameState>();
  gameState->initMiniGameClasses();

///   miniGameCombat().start(Difficulty::Level1);
///   miniGameCrypto().start(Difficulty::Level1);
///   miniGameDriving().start(Difficulty::Level1);
///   miniGameElec().start(Difficulty::Level1);

///   MiniGameCombat::Instance().start(Difficulty::Level1);

  SDL_SetMainReady();
  SDL_Init(SDL_INIT_EVERYTHING);

  gui = std::make_unique<GUI>();
  gui->initGUI();
  gui->createGUI(gameState->currentScreen);

  play_music();

  bool quit = false;
  SDL_Event e;
  while(!quit) {
    if (gui->refreshNow()) {
      gui->updateGUI();
    }
    while(SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT)  { quit = true; }
    }

///     if (SDL_GetTicks64() > gui->next_screen_tick) {
///       gameState->currentScreen = gameState->getNextScreen();  // TODO: gameState++;
///       gui->createGUI(gameState->currentScreen);  // TODO: remove argument
///     }
  }

///   TTF_Quit();
  SDL_Quit();  // TODO: replace with each subsystem quit by ref?

  return EXIT_SUCCESS;
}

