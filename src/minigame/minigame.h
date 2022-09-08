//
// Created by wright on 05/09/22.
//

#ifndef __MINIGAME_H
#define __MINIGAME_H

// TODO: common functions e.g. timer, draw, event handling, loop, etc.

class MiniGame {
    virtual void draw() = 0;
protected:
    MiniGame() = default;
};

#endif
