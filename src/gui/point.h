#pragma once

#ifndef NO_SDL
#include <SDL_rect.h>
#endif

// TODO: replace with SDL_Point
/*
class Point {
public:
    Point() = default;
    Point(SDL_Rect rect) : dstRect{rect}  {}
    ~Point() = default;

    Point operator++(int)  { dstRect.y += 8; return *this; }

    int getX()  { return this->dstRect.x; }
    int getY()  { return this->dstRect.y; }

/// private:
    SDL_Rect dstRect {0, 0, 320, 200};
};
// */
