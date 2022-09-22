#pragma once

#include <random>

#include "minigame.h"


enum TopSpeed {
  MPH40 = 40,
  MPH60 = 60,
  MPH80 = 80,
};


struct Car {
  TopSpeed top_speed;
  bool tracking;
  bool uturns;
  signed char suspicion;
  int x;
  int y;
  int speed;
  int direction;  // TODO: direction enum (move to types)
};  // TODO: typedef?


enum MissionGoal {
  FOLLOW,
  CAPTURE,
  ESCAPE,
};


class MiniGameDriving : public MiniGame {
public:
  MiniGameDriving();
  int start(Difficulty level);
  void draw() override;
  Difficulty getGameDifficulty() override;
private:
  MissionGoal mission_goal;
  Car car1;
  Car car2;  // own car when is_predator, otherwise enemy
  Car car3;
  unsigned char unseen_timer;
};
