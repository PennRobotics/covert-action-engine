#define SDL_MAIN_HANDLED  // TODO: needed?

#include "covert.h"

#include "gameplay/gamestate.h"
#include "gameplay/mainchar.h"
/// #include "gui/gui.h"

#include <SDL_stdinc.h>
#include <SDL.h>

//TODO-debug
#include <iostream>

extern int case_gen();
extern Agent agent_gen();


// TODO: enforce variable casing
// TODO: style guide
// TODO: consistency in spec (unique_ptr vs new)


// TODO
std::unique_ptr<MainChar> mainChar;
std::unique_ptr<GameState> gameState;

extern void play_music(MidiFile);

static const SDL_Keycode mapDOWN = SDLK_DOWN;  // TODO: key mapping
static const SDL_Keycode mapUP = SDLK_UP;

namespace kbd {
void handler(SDL_Event& e);
}

int do_covert()
{
  mainChar = std::make_unique<MainChar>();

  gameState = std::make_unique<GameState>();
  gameState->initGUI();
  gameState->createGUI(gameState->currentScreen);

  SDL_SetMainReady();
  SDL_Init(SDL_INIT_EVERYTHING);

  play_music(MidiFile::Intro);

  // TODO-debug
  Agent q = agent_gen();
  std::cout << q.Name << std::endl;

  bool quit = false;
  SDL_Event e;
  while(!quit) {
    if ( gameState->guiShouldRefresh() ) {  // TODO-debug
      gameState->getNextScreen();
      gameState->createGUI(gameState->currentScreen);
    }
    while(SDL_PollEvent(&e) != 0) {
      switch (e.type) {
        case SDL_QUIT:
          quit = true;
          break;
        case SDL_KEYDOWN:
          kbd::handler(e);
          break;
        default:
          break;
      }  // e->type
    }
  }

  SDL_Quit();  // TODO: replace with each subsystem quit by ref?

  return EXIT_SUCCESS;
}

namespace kbd {
void handler(SDL_Event& e) {
  switch ( gameState->dialogType ) {
    case DialogType::INFOTIMER:
    case DialogType::INFO:
      switch (e.key.keysym.sym) {
        default:
          printf("%ld\n", static_cast<unsigned long>(e.key.keysym.sym));  // TODO: clean this shit up
          break;
      }
      break;
    case DialogType::MENU:
    case DialogType::MINIMENU:
      switch (e.key.keysym.sym) {
        case mapDOWN:
          printf("down\n");
          break;
        case mapUP:
          printf("up\n");
          break;
      }  // ...keysym.sym
      break;
    case DialogType::TEXTENTRY:
      // TODO
      break;
    case DialogType::SKILLSELECT:
      switch (e.key.keysym.sym) {  // TODO
        case mapDOWN:
          printf("down\n");
          break;
        case mapUP:
          printf("up\n");
          break;
      }  // ...keysym.sym
      break;
    case DialogType::MINIGAME:
    default:
      break;
  }  // gameState->guiGetDialogType
}
}
