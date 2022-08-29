#include "casegenerator.h"


int case_gen() { // TODO-debug
  missions.reserve(NUM_MISSION_TYPES);

  std::ifstream infile{"mission.dat"};
  std::string s;
  do {
    getline(infile, s);
    if (s.substr(0, 2) == "# ") {
      missions.push_back(Mission(s.substr(2)));
    }
    if (s.substr(0, 2) == "- ") {
      missions.back().addParticipant(s.substr(2));
    }
  } while (s != "");
  for (auto& mission : missions) {
    mission.printOverview();
  }
  return 0;
}
