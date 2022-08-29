#include "combat.h"


MiniGameCombat::MiniGameCombat() {
  std::cout << "CO\n";
}


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

  return 0;  // TODO
}


void draw() {
  // TODO
}
