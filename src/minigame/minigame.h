#ifndef CA_MINIGAME_H
#define CA_MINIGAME_H

#include "../types.h"

// TODO: common functions e.g. timer, draw, event handling, loop, etc.

class MiniGame {
    virtual void draw() = 0;
    virtual Difficulty getGameDifficulty() = 0;
protected:
    MiniGame() = default;
};

#endif
