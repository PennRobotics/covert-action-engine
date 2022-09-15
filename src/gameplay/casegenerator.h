#ifndef CA_CASEGENERATOR_H
#define CA_CASEGENERATOR_H

#include <fstream>
#include <string>
#include <vector>

#define NUM_MISSION_TYPES 13

int case_gen();

struct Organization {
  std::string full_name;
  std::string abrv;
  char id_char;  // TODO: type
};

Organization ownOrg = Organization{"CIA", "CIA", '?'};

static const std::array<Organization, 3> alliedOrg {
  Organization{"KGB", "KGB", '!'},
  Organization{"MI6", "MI6", '@'},
  Organization{"Mossad", "Mossd", '#'},
};  

enum {
  AMAZON_CARTEL = 'a',  // TODO: better this way?
  COLUMBIAN_CARTEL = 'b',
};

static const std::array<Organization, 26> crimeOrg {
  Organization{"Amazon Cartel", "?", 'a'},  // TODO: assign the correct letters and abbrevs
  Organization{"Colombian Cartel", "?", COLUMBIAN_CARTEL},
  Organization{"Death Squads", "?", 'c'},
  Organization{"Dignity Battalion", "?", 'd'},
  Organization{"Direct Action", "DActn", 'e'},
  Organization{"FLN", "?", 'f'},
  Organization{"Haitian Junta", "?", 'g'},
  Organization{"IraqiSP", "IrqSP", 'h'},
  Organization{"Jamaican Gang", "?", 'i'},
  Organization{"Libyan Embassy", "LibEb", 'j'},
  Organization{"M18", "M18", 'k'},
  Organization{"Mafia", "Mafia", 'l'},
  Organization{"Marxists", "Mrxst", 'm'},
  Organization{"Mercenaries", "?", 'n'},
  Organization{"Muslim Jihad", "?", 'o'},
  Organization{"PIFA", "PIFA", 'p'},
  Organization{"PFO", "PFO", 'q'},
  Organization{"PRC", "PRC", 'r'},
  Organization{"Red Army", "RArmy", 's'},
  Organization{"Red Battalion", "RedBt", 't'},
  Organization{"Red September", "?", 'u'},
  Organization{"Revolutionary Guards", "?", 'v'},
  Organization{"Shining Way", "?", 'w'},
  Organization{"Stassi", "Stasi", 'x'},
  Organization{"Tupamaros", "?", 'y'},
  Organization{"UnionCorsique", "Union", 'z'},
};   


std::string generateName(Organization org) {
  switch (org.id_char) {
    case COLUMBIAN_CARTEL:
      return std::string("Anita Todo");
    default:
      return std::string("Mark Todo");  // TODO: will the compiler complain if this isn't at the function end?
  }
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
  uint8_t      visibility;
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
  this->visibility = 0x40;
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
///   std::cout << this->name << std::endl;
///   std::cout << std::string(this->name.length(), '=') << std::endl;
///   for (auto& party : this->participants) {
///     std::cout << party.getName() << ", " << party.getRole() << std::endl;
///   }
}

std::vector<Mission> missions;  // TODO: switch to a set type with name as key

#endif
