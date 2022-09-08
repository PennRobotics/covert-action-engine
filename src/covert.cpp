#include <SDL_stdinc.h>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_image.h>

#include <memory>
#include <string>  // TODO-debug

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



static std::unique_ptr<MainChar> mainChar;
static std::unique_ptr<GUI> gui;
static std::unique_ptr<GameState> gameState;

// TODO

int do_covert()
{
  mainChar = std::make_unique<MainChar>();

  gameState = std::make_unique<GameState>();
  gameState->initMiniGameClasses();

  gui = std::make_unique<GUI>();
  gui->initGUI();
  gui->createGUI(gameState->currentScreen);

  play_music();

  bool quit = false;
  SDL_Event e;
  while(!quit) {
    while(SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT)  { quit = true; }
    }

    if (SDL_GetTicks64() > gui->next_screen_tick) {
      gameState->currentScreen = gameState->getNextScreen();  // TODO: gameState++;
      gui->createGUI(gameState->currentScreen);  // TODO: remove argument
    }
  }

  TTF_Quit();
  SDL_Quit();  // TODO: replace with each subsystem quit by ref?

  return EXIT_SUCCESS;
}

