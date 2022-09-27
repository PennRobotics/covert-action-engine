#define SDL_MAIN_HANDLED  // TODO: needed?

#include "covert.h"

#include "gameplay/gamestate.h"
#include "gameplay/mainchar.h"

#ifndef NO_SDL
#include <SDL_stdinc.h>
#include <SDL.h>
#else
typedef int32_t SDL_Keycode;
enum {
	SDLK_RETURN = 13,
	SDLK_ESCAPE = 27,
	SDLK_LEFT = 37,
	SDLK_UP = 38,
	SDLK_RIGHT = 39,
	SDLK_DOWN = 40,
};
void SDL_Quit()  {}
#endif

extern int case_gen();
extern Agent agent_gen();


// TODO: enforce variable casing
// TODO: style guide
// TODO: consistency in spec (unique_ptr vs new)


std::unique_ptr<MainChar> mainChar;
std::unique_ptr<GameState> gameState;

#ifndef NO_SDL
extern void play_music(MidiFile);
#endif

static const SDL_Keycode mapDOWN = SDLK_DOWN;  // TODO: key mapping
static const SDL_Keycode mapUP = SDLK_UP;
static const SDL_Keycode mapLEFT = SDLK_LEFT;
static const SDL_Keycode mapRIGHT = SDLK_RIGHT;
static const SDL_Keycode mapENTER = SDLK_RETURN;
static const SDL_Keycode mapESC = SDLK_ESCAPE;

#ifndef NO_SDL
namespace kbd {
void handler(SDL_Event& e);
}
#endif

int do_covert()
{
  mainChar = std::make_unique<MainChar>();

  gameState = std::make_unique<GameState>();
  gameState->initGUI();
  gameState->createGUI(gameState->currentScreen);

#ifndef NO_SDL
  SDL_SetMainReady();
  SDL_Init(SDL_INIT_EVERYTHING);

  play_music(MidiFile::Intro);
#endif

  Agent q = agent_gen();

  bool quit = false;
#ifndef NO_SDL
  SDL_Event e;
#endif
  while(!quit) {
    if ( gameState->guiShouldRefresh() ) {  // TODO-debug
      gameState->getNextScreen();
      gameState->createGUI(gameState->currentScreen);
    }
#ifndef NO_SDL
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
#else
	// TODO: Get to OS exit first, replace this with non-SDL event handler, restore infinite loop
	/// while(1)  {}
#endif
  }

  SDL_Quit();  // TODO: replace with each subsystem quit by ref?

  return EXIT_SUCCESS;
}

#ifndef NO_SDL
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
          gameState->chooseMenuNext();
          break;
        case mapUP:
          printf("up\n");
          gameState->chooseMenuPrev();
          break;
        case mapENTER:
          gameState->selectMenuState();
          gameState->getNextScreen();
        case mapESC:
          gameState->selectMenuDefault();
          gameState->getNextScreen();
      }  // ...keysym.sym
      gameState->createGUI(gameState->currentScreen);
      break;
    case DialogType::TEXTENTRY:
      // TODO
      break;
    case DialogType::SKILLSELECT:
      switch (e.key.keysym.sym) {  // TODO
        case mapLEFT:
          printf("L\n");
          break;
        case mapRIGHT:
          printf("R\n");
          break;
      }  // ...keysym.sym
      break;
    case DialogType::MINIGAME:
    default:
      break;
  }  // gameState->guiGetDialogType
}
}
#endif
