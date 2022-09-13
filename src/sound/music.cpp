#include <SDL_mixer.h>
#include <SDL.h>

#include "music.h"

const char* fnames[] = { "test.wav", };
static Mix_Chunk *wave[1];

void play_music() {
  memset(wave, 0, sizeof(wave));

  Mix_OpenAudio(48000, AUDIO_S16SYS, 2, 512);  // TODO: determine why sporadic static noise occurs when set to 44100
  Mix_AllocateChannels(4);
  wave[0] = Mix_LoadWAV(fnames[0]);
  fprintf(stdout, "AB%d\n", (uint64_t) wave[0]);

///   Mix_PlayChannel(-1, wave[0], 0);

///   SDL_Delay(2000);

  Mix_FreeChunk(wave[0]);
  Mix_CloseAudio();
}