#pragma once

#include <vector>

/// #include "../types.h"

/* TODO: determine best city structure */

class Theater {
public:
  Theater();
  void populateCityList();
  std::vector<City> cities;
  std::vector<Org> orgs;
  Image atlasImage;
  std::vector<Mastermind> atLarge;
};
class Africa : Theater  {};
class America : Theater  {};
class Europe : Theater  {};



// TODO: distance between each city (xy-derived or table?)
