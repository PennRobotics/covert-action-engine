#ifndef CA_GFX_H
#define CA_GFX_H

#include <string>

#include <SDL_image.h>

namespace Color {
    SDL_Color BLACK = {0x00, 0x00, 0x00};
    SDL_Color DKRED = {0xAA, 0x00, 0x00};
    SDL_Color DKGREEN = {0x00, 0xAA, 0x00};
    SDL_Color BROWN = {0xAA, 0x55, 0x00};
    SDL_Color DKBLUE = {0x00, 0x00, 0xAA};
    SDL_Color UNK = {0x00, 0x00, 0x00};
    SDL_Color DKCYAN = {0x00, 0xAA, 0xAA};
    SDL_Color GREY = {0xAA, 0xAA, 0xAA};
    SDL_Color DKGREY = {0x55, 0x55, 0x55};
    SDL_Color RED = {0xFF, 0x55, 0x55};
    SDL_Color GREEN = {0x55, 0xFF, 0x55};
    SDL_Color YELLOW = {0xFF, 0xFF, 0x55};
    SDL_Color BLUE = {0x55, 0x55, 0xFF};
    SDL_Color MAGENTA = {0xFF, 0x55, 0xFF};
    SDL_Color CYAN = {0x55, 0xFF, 0xFF};
    SDL_Color WHITE = {0xFF, 0xFF, 0xFF};
}

void render_bg(SDL_Color& c);

void render_text(uint16_t& x, uint16_t& y, std::string& text, SDL_Color& c);

void render_bar(uint16_t& x, uint16_t& y, uint16_t& w, uint16_t& h, SDL_Color& c);

#endif
