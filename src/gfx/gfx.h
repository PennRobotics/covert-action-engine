#pragma once

/// #include <string>

#ifndef NO_SDL
#include <SDL_image.h>
#else
typedef struct SDL_Color  { uint8_t r,g,b,a }  SDL_Color;
#endif

void render_bg(SDL_Color& c);

void render_text(uint16_t& x, uint16_t& y, std::string& text, SDL_Color& c);

void render_bar(uint16_t& x, uint16_t& y, uint16_t& w, uint16_t& h, SDL_Color& c);
