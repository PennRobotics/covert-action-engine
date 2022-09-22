#pragma once

/// #include <string>

#include <SDL_image.h>

void render_bg(SDL_Color& c);

void render_text(uint16_t& x, uint16_t& y, std::string& text, SDL_Color& c);

void render_bar(uint16_t& x, uint16_t& y, uint16_t& w, uint16_t& h, SDL_Color& c);
