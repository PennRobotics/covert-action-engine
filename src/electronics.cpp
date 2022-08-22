#include "electronics.h"
#include <string>  // TODO-debug


MiniGameElectronics::MiniGameElectronics() {
  std::cout << "EL\n";
}


int MiniGameElectronics::start(difficulty level) {
  int num_locked;
  int num_hidden;
  int num_alarms;
  int num_jumps;
  int num_swaps;
  int highest_random = 4 + 2 * (int)level;
  std::random_device seeder;
  std::mt19937 rng(seeder());
  std::uniform_int_distribution<> distrib(1, highest_random);

  sx = 0;
  sy = 0;

  // Randomize junctions
  for (auto& row : junction_matrix) {
    for (auto& elem : row) {
      elem.junction = (Junction)distrib(rng);
    }
  }


  draw();

  // Randomize crossings

  std::cout << "L" << (int)level << std::endl;
  return 0;
}


void MiniGameElectronics::draw() {
  for (auto& row : junction_matrix) {
    for (auto& elem : row) {
      std::string s;  // TODO-debug
      switch (/*TODO: type*/(int)elem.junction) {
        case 1:  s = " = "; break;
        case 2:  s = " X "; break;
        case 3:  s = " 3 "; break;
        case 4:  s = " 4 "; break;
        case 5:  s = " 5 "; break;
        case 6:  s = " 6 "; break;
        case 7:  s = " 7 "; break;
        case 8:  s = " 8 "; break;
        default: s = "!!!"; break;
      }
      if (elem.hidden)  { s = "[ ]"; }
      if (elem.locked)  { s = ">" + s.substr(1,1) + "<"; }
      std::cout << s;
    }
    std::cout << std::endl;
  }
}
