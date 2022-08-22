#include <iostream>
#include <random>

#include "types.h"


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


class MiniGameDriving {
public:
  MiniGameDriving();
  int start(difficulty level);
private:
  void draw();
  bool is_predator;
  Car car1;
  Car car2;  // own car when is_predator, otherwise enemy
  Car car3;
};




