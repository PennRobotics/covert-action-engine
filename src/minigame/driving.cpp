#include "driving.h"


    #if defined(TEST_ACTIVE)
    #include <iostream>
    #endif
MiniGameDriving::MiniGameDriving() {
#if defined(TEST_ACTIVE)
  std::cout << "DRIVING MINIGAME CLASS CREATED\n";
#endif
}


int MiniGameDriving::start(Difficulty level) {
  // TODO
  return 0;
}

void MiniGameDriving::draw() {
  // TODO
}

Difficulty MiniGameDriving::getGameDifficulty() {
  return Difficulty::Level1;  // TODO
}

