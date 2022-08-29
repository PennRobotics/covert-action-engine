#include <fstream>
#include <iostream>
//#include <string>
#include <vector>


#define NUM_MISSION_TYPES 13

typedef std::string Organization;

class OClass {
public:
  OClass()  { this->org = "TODORG"; }
protected:
  std::string org;
};

std::string generateName(Organization org) {
  if (org == "TODORG") {
    return std::string("Alice Todo");
  }
  return std::string("Mark Todo");
}


class City  { public: City(){} };  // TODO

enum class Rank : uint16_t {
  Nobody = 0,
  Operative = 20,
  Technician = 25,
  Agent = 30,
  Organizer = 35,
  SpecialAgent = 40,
  GroupLeader = 45,
  Mastermind = 200,
};


enum class Status {
  AtLarge,
  RedHerring,
  DoubleAgent,
  Arrested,
  InHiding,
};

class Participant : OClass {
public:
  Participant(std::string role);

  std::string getName()  { return this->name; };
  std::string getAgentLetter()  { return this->agentletter; };
  uint16_t getRankPoints()  { return static_cast<uint16_t>(this->rank); };
  std::string getRole()  { return this->role; };

private:
  std::string  name;  // TODO: change types
  std::string  agentletter;
  Rank         rank;
  City         city;
  Organization affiliation;
  City         recruitcity;
  Participant* p_recruiter;
  std::string  role;
  Status       status;
};

Participant::Participant(std::string role) {
  this->name = generateName(org);  // TODO: fix inheritance
  this->agentletter = std::string("Q");  // TODO: pickRandomUnusedLetter();
  this->rank = Rank::Operative;
  this->city = City();
  this->affiliation = Organization();
  this->recruitcity = City();
///   this->recruiter = ...;  // TODO: these need to point to each other, so create a recruiter linkage function after all participants are created
  this->role = role;
  this->status = Status::AtLarge;
}


class Mission {
public:
  Mission(std::string name)  { this->name = name; }
  void addParticipant(std::string role)  { this->participants.push_back(Participant(role)); }
  void printOverview();

private:
  std::string name;
  std::vector<Participant> participants;
  /* TODO */
};


class MissionSet {
public:
  MissionSet(Mission m1, Mission m2, Mission m3)  {}  // TODO: direct init
};


void Mission::printOverview() {
  std::cout << this->name << std::endl;
  std::cout << std::string(this->name.length(), '=') << std::endl;
  for (auto& party : this->participants) {
    std::cout << party.getName() << ", " << party.getRole() << std::endl;
  }
}

std::vector<Mission> missions;  // TODO: switch to a set type with name as key

int main() { // TODO-debug
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
}
