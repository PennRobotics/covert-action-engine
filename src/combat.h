#include <iostream>
#include <vector>

#include "types.h"


/* TODO:
 * - door choice
 * - fast angle math e.g. sin 16-bit signed: bitshift(in, 1) - bitshift(abs(in), -7).*bitshift(in,-7) 
 * - minimap update
 * - sprite animations
 * - surveillance quality
 * - terminals
 * - booby traps
 * - grenade radii
 *   - up to 3 adjacent tiles
 * - timed events
 *   - gas
 *   - stun
 *   - alarm
 * - time passing after exit
 */


enum Direction {
  TOP,
  TOPRIGHT,
  RIGHT,
  BOTTOMRIGHT,
  BOTTOM,
  BOTTOMLEFT,
  LEFT,
  TOPLEFT,
};


struct Person {
  int x;
  int y;
  Direction dir;
  int ko_timer;
  // TODO
};


struct Inventory {
  bool uzi;
  bool gas_mask;
  bool motion_detector;
  bool camera;
  bool kevlar_armor;
  bool safecracking_kit;
  bool disguise;
  unsigned char bugs;
  unsigned char frags;
  unsigned char gasses;
  unsigned char stuns;
  unsigned char rounds;
  unsigned char mags;
  int accuracy_pct;
};


class MiniGameCombat {
public:
  MiniGameCombat();
  int start(difficulty level);
protected:  // TODO?
  Inventory inv;
private:
  void draw();
  unsigned char max_guards;
  std::vector<Person> population;
};

