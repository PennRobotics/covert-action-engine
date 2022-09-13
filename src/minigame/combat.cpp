#include "combat.h"


    #if defined(TEST_ACTIVE)
    #include <iostream>
    #endif
MiniGameCombat::MiniGameCombat() {
#if defined(TEST_ACTIVE)
  std::cout << "COMBAT MINIGAME CLASS CREATED\n";
#endif
}


#include <iostream>  // TODO-debug
int MiniGameCombat::start(Difficulty level) {
  inv.uzi = false;
  inv.gas_mask = false;
  inv.motion_detector = false;
  inv.camera = false;
  inv.kevlar_armor = false;
  inv.safecracking_kit = false;
  inv.bugs = 0;
  inv.frags = 0;
  inv.gasses = 0;
  inv.stuns = 0;
  inv.rounds = 6;
  inv.mags = 3;
  inv.accuracy_pct = -1;

  std::cout << "mgc start\n";
  return 0;  // TODO
}

void MiniGameCombat::draw() {
    // TODO
}

MiniGameCombat& MiniGameCombat::Instance() {
  static MiniGameCombat instance;
  return instance;
}

Difficulty MiniGameCombat::getGameDifficulty() {
  return Difficulty::Level1;  // TODO
}