#ifndef CA_AGENTGENERATOR_H
#define CA_AGENTGENERATOR_H

#include <cstdint>
#include <string>
#include <vector>

void genTwoDoubleAgents();

struct Face {
    uint8_t gender_id;
    uint8_t hair_id;
    uint8_t eye_id;
    uint8_t skin_id;
    uint8_t clothing_id;
    uint8_t accessory_id;
};

using callsign_t = std::string;
using city_t = std::vector<uint8_t>;  // TODO: change this type and all below
using org_t = std::vector<uint8_t>;
using rank_t = std::vector<uint8_t>;
using role_t = std::vector<uint8_t>;
using casedata_t = std::vector<uint8_t>;

struct Agent {
    callsign_t Name;
    Face Photo;
    city_t Location;
    org_t Affiliation;
    rank_t Rank;
    role_t Role;
    city_t RecruitedIn;
    Agent* RecruitedBy;
    casedata_t Data;
} agent;

#endif
