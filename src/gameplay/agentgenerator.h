//
// Created by wright on 06/09/22.
//

#ifndef SPNA_GAME_AGENTGENERATOR_H
#define SPNA_GAME_AGENTGENERATOR_H


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

typedef std::string callsign;
typedef std::vector<uint8_t> city;  // TODO: change this type and all below
typedef std::vector<uint8_t> org;
typedef std::vector<uint8_t> rank;
typedef std::vector<uint8_t> role;
typedef std::vector<uint8_t> casedata;

struct Agent {
    callsign Name;
    Face Photo;
    city Location;
    org Affiliation;
    rank Rank;
    role Role;
    city RecruitedIn;
    Agent* RecruitedBy;
    casedata Data;
} agent;

#endif //SPNA_GAME_AGENTGENERATOR_H
