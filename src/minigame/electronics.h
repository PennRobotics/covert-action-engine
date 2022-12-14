#pragma once

#include <random>
//#include <utility>
#include <array>

#include "minigame.h"
/// #include "../gameplay/gamestate.h"
/// #include "../covert.h"


/// #include "../covert.h"

enum Junction {
  STRAIGHT = 1,
  CROSS,
  TOP_TO_ALL,
  BOT_TO_ALL,
  ALL_TO_TOP,
  ALL_TO_BOT,          // Level I
  STRAIGHT_INV_TOP,
  STRAIGHT_INV_BOT,    // Level II
  STRAIGHT_INV_ALL,
  CROSS_INV_TOP_LEFT,  // Level III
  CROSS_INV_BOT_LEFT,
  CROSS_INV_ALL,       // Level IV
};


struct Junc {
  Junction junction;
  bool hidden;
  bool locked;
};  // TODO: typedef?


class MiniGameElectronics : public MiniGame {
public:
  MiniGameElectronics();
  ~MiniGameElectronics() = default;  // TODO
  int start(Difficulty level);
  void draw() override;
  Difficulty getGameDifficulty() override;
private:
  unsigned char sx;
  unsigned char sy;
  std::array<std::array<Junc, 7>, 5> junction_matrix;
  std::array<std::array<bool, 6>, 8> crossing_matrix;
  Junc holding;
};
