#include <SDL_stdinc.h>

#include <SDL.h>
#include <SDL_mixer.h>

#include <memory>
#include <string>  // TODO-debug

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

// TODO
static Mix_Chunk *wave = NULL;

int main()
{
  SDL_Window* window = NULL;
  SDL_Surface* screen_surface = NULL;

  int audio_rate = MIX_DEFAULT_FREQUENCY;
  uint16_t audio_fmt = MIX_DEFAULT_FORMAT;
  int audio_chs = MIX_DEFAULT_CHANNELS;
  int i;

///   SDL_Init(SDL_INIT_TIMER);  // timer subsystem
  SDL_Init(SDL_INIT_AUDIO);  // audio subsystem
///   SDL_Init(SDL_INIT_VIDEO);  // video subsystem; automatically initializes the events subsystem
///   SDL_Init(SDL_INIT_JOYSTICK);  // joystick subsystem; automatically initializes the events subsystem
///   SDL_Init(SDL_INIT_HAPTIC);  // haptic (force feedback) subsystem
///   SDL_Init(SDL_INIT_GAMECONTROLLER);  // controller subsystem; automatically initializes the joystick subsystem
///   SDL_Init(SDL_INIT_EVENTS);  // events subsystem
///   SDL_Init(SDL_INIT_EVERYTHING);  // all of the above subsystems
///   SDL_Init(SDL_INIT_NOPARACHUTE);  // compatibility; this flag is ignored

  // TODO-debug start
  Mix_OpenAudio(audio_rate, audio_fmt, audio_chs, 4096);
  Mix_QuerySpec(&audio_rate, &audio_fmt, &audio_chs);
  wave = Mix_LoadWAV("test.wav");
  Mix_PlayChannel(0, wave, 0);

  goto eject;

///   SDL_zero(want);
///   want.freq = 48000;
///   want.format = AUDIO_F32;
///   want.channels = 2;
///   want.samples = 4096;
///   want.callback = NULL;  // valid >= 2.0.4
///   audiodev = SDL_OpenAudioDevice(NULL, 0, &want, &have, SDL_AUDIO_ALLOW_ANY_CHANGE);
/// 
///   std::cout << "[" << audiodev << "]" << std::endl;
/// 
///   const int num_audio_devs = SDL_GetNumAudioDevices(0);
///   std::cout << "<" << num_audio_devs << ">" << std::endl;
///   for (int i = 0; i < num_audio_devs; ++i) {
///     std::string u8adname = SDL_GetAudioDeviceName(i, 0);
///     std::cout << " " << i;
///   }
/// 
///   uint8_t *a_buf;
///   uint32_t a_len;
///   SDL_LoadWAV("test.wav", &have, &a_buf, &a_len);
///   struct sample {
///     uint8_t *data;
///     uint32_t pos;
///     uint32_t len;
///   } samples;
/// 
///   SDL_AudioCVT cvt;
///   SDL_BuildAudioCVT(&cvt, have.format, have.channels, have.freq, AUDIO_S16, 2, 22050);
/// 
///   SDL_LockAudio();
/// 
///   samples.data = cvt.buf;
///   samples.len = cvt.len_cvt;
///   samples.pos = 0;
/// 
///   SDL_PauseAudio(0);
///   // TODO-debug end
/// 
///   goto eject;

  std::cout << SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) << "\n";
  //std::cout << TTF_Init() << "\n";
  window = SDL_CreateWindow("UP", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  screen_surface = SDL_GetWindowSurface(window);

  SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0xEF, 0xFF, 0xEF));
  SDL_UpdateWindowSurface(window);

  // TODO: audio, resources, etc.

eject:
  SDL_Delay(4000);
/// 
///   SDL_UnlockAudio();
///   SDL_FreeWAV(a_buf);
  SDL_DestroyWindow(window);

  // for(;;){}
  //TTF_Quit();
  SDL_Quit();  // TODO: replace with each subsystem quit by ref?

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

