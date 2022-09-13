#ifndef CA_COMBAT_H
#define CA_COMBAT_H

#include <vector>

#include "minigame.h"


/* TODO:
 * - door choice
 * - fast angle math e.g. sin 16-bit signed: bitshift(in, 1) - bitshift(abs(in), -7).*bitshift(in,-7) 
 * - minimap update
 * - furniture sprites
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


struct Room {
  /*
  room_type,
  furniture_vector,
  has_bug,  // How does surveillance factor change with multiple break-ins and over long times?
  gas_active,  // Are the effects stronger with multiple active grenades?
  gas_start_time,
  */
};


struct Furniture {
  /*
  type,
  is_opened,
  is_photographed,
  is_bugged,
  */
};
  


class MiniGameCombat : public MiniGame {
public:
  MiniGameCombat(MiniGameCombat&) = delete;
  void operator=(const MiniGameCombat) = delete;
  static MiniGameCombat& Instance();
  int start(Difficulty level);
protected:  // TODO?
  Inventory inv;
private:
  MiniGameCombat();
  void operator delete(void*) {};

  void draw() override;
  Difficulty getGameDifficulty() override;
  unsigned char max_guards;
  std::vector<Person> population;
};

#endif