#include <iostream>
#include <vector>

#include "types.h"


enum Direction {
  U,
  L,
  R,
  D,
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
  std::vector<Person> population;
};

