typedef callsign std::string;

struct Face {
  uint8_t gender_id;
  uint8_t hair_id;
  uint8_t eye_id;
  uint8_t skin_id;
  uint8_t clothing_id;
  uint8_t accessory_id;
} face;

/* TODO: determine best city structure */

class Theatre {
  std::vector<city> cities;
  std::vector<org> orgs;
  image atlas;
  std::vector<mastermind> at_large;
};
class America : Theater  {};
class Africa : Theater  {};
class Europe : Theater  {};

// TODO: distance between each city (xy-derived or table?)



struct Agent {
  callsign Name;
  face Photo;
  city Location;
  org Affiliation;
  rank Rank;
  role Role;
  city RecruitedIn;
  agent RecruitedBy;
  casedata Data;
} agent;



