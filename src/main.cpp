#include <SDL_stdinc.h>

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <memory>
#include <string>  // TODO-debug

#include "types.h"

extern int case_gen();

#include "combat.h"
#include "driving.h"
#include "cryptography.h"
#include "electronics.h"
#include "menu.h"

class MainChar {
public:
  static MainChar& getInstance();
///   void setNickname(std::string s)  { this->nickname = s; }
///   std::string getNickname()  { return this->nickname; }
/// protected:
///   std::string nickname;
private:
  MainChar() = default;
  ~MainChar() = default;
  MainChar(const MainChar&) = delete;
  MainChar& operator=(const MainChar&) = delete;
};

MainChar& MainChar::getInstance() {
  static MainChar instance;
  return instance;
}


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

// TODO
const char* fnames[] = { "test.wav", };
static Mix_Chunk *wave[1];

int main()
{
  MainChar::getInstance();

  case_gen();

  SDL_Window* window = NULL;
  SDL_Surface* screen_surface = NULL;

  SDL_Init(SDL_INIT_EVERYTHING);  // all of the above subsystems

  const char* fname = "test.ttf";
  SDL_RWops* rwops = SDL_RWFromFile(fname, "rb");
  TTF_Font* ttf = TTF_OpenFontRW(rwops, 1, 18);

  SDL_Color test = {255, 0, 255, 255};
  SDL_Renderer* renderer;
  SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
  SDL_RenderClear(renderer);

  memset(wave, 0, sizeof(wave));

  Mix_OpenAudio(48000, AUDIO_S16SYS, 2, 512);  // TODO: determine why static occurs when set to 44100
  Mix_AllocateChannels(4);
  wave[0] = Mix_LoadWAV(fnames[0]);

  Mix_PlayChannel(-1, wave[0], 0);

  std::cout << TTF_Init() << "\n";

  window = SDL_CreateWindow("UP", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  screen_surface = SDL_GetWindowSurface(window);

  SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0xEF, 0xFF, 0xEF));
  SDL_UpdateWindowSurface(window);

  // TODO: audio, resources, etc.

  SDL_Delay(4000);

  Mix_FreeChunk(wave[0]);
  Mix_CloseAudio();

  TTF_Quit();
  SDL_Quit();  // TODO: replace with each subsystem quit by ref?

  /*
  mGameCombat = std::make_unique<MiniGameCombat>();
  mGameDriving = std::make_unique<MiniGameDriving>();
  mGameCrypto = std::make_unique<MiniGameCryptography>();
  mGameElec = std::make_unique<MiniGameElectronics>();

  mGameCombat->start(Difficulty::Level2);
  mGameDriving->start(Difficulty::Level2);
  mGameCrypto->start(Difficulty::Level2);
  mGameElec->start(Difficulty::Level2);
  */

  return 0;
}

