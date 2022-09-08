//
// Created by wright on 05/09/22.
//

#ifndef SPNA_GAME_POINT_H
#define SPNA_GAME_POINT_H


#include <SDL_rect.h>

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


#endif //SPNA_GAME_POINT_H