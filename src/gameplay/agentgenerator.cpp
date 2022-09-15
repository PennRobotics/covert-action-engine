#include "agentgenerator.h"

Agent b;

Agent agent_gen() {
  Agent a;

  a.Name = std::string("Test");
  a.Photo = Face{0,1,2,3,4,5};
  a.Location = {4};
  a.Affiliation = {6};
  a.Rank = {3};
  a.Role = {1};
  a.RecruitedIn = {1};
  a.RecruitedBy = {&b};
  a.Data = {1,2,3,4};

  return a;
}
