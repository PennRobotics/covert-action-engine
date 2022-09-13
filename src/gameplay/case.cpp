#include "case.h"

    #if defined(TEST_ACTIVE)
    #include <iostream>
    #endif
Theater::Theater() {
#if defined(TEST_ACTIVE)
std::cout << "GENERIC THEATER CLASS CREATED\n";
#endif
}

#define  AFRICA_CITY_LIST  { \
    {"Amman", "Jordan",             0,   0, TEXT_x}, \
    {"Washington", "D.C.",          0,  40, TEXT_x}, \
    {"Athens", "Greece",           95,   0, TEXT_x}, \
    {"Baghdad", "Iraq",             0,   0, TEXT_x}, \
    {"Beirut", "Lebanon",         135,   0, TEXT_x}, \
    {"Cairo", "Egypt",            110, 100, TEXT_x}, \
    {"Damascus", "Syria",           0,   0, TEXT_x}, \
    {"Istanbul", "Turkey",        100,   0, TEXT_x}, \
    {"Khartoum", "Sudan",         115, 120, TEXT_x}, \
    {"London", "England",           0,  40, TEXT_x}, \
    {"Paris", "France",             0,   0, TEXT_x}, \
    {"Riyadh", "Saudi Arabia",      0,   0, TEXT_x}, \
    {"Rome", "Italy",               0,   0, TEXT_x}, \
    {"Tehran", "Iran",              0,   0, TEXT_x}, \
    {"Tel Aviv", "Israel",          0,   0, TEXT_x}, \
    {"Tripoli", "Libya",            0,   0, TEXT_x}}


#define  AMERICA_CITY_LIST  { \
    {"Bogota", "Columbia",        110, 100, TEXT_R}, \
    {"Washington", "D.C.",        155,   4, TEXT_L}, \
    {"Caracas", "Venezuela",      135,  90, TEXT_R}, \
    {"Havana", "Cuba",             95,  50, TEXT_R}, \
    {"Kingston", "Jamaica",       120,  70, TEXT_R}, \
    {"London", "England",         199,  10, TEXT_L}, \
    {"Los Angeles", "U.S.A.",       3,   4, TEXT_R}, \
    {"Managua", "Nicaragua",       70,  70, TEXT_R}, \
    {"Medellin", "Colombia",      102,  95, TEXT_R}, \
    {"Mexico City", "Mexico",      40,  55, TEXT_R}, \
    {"Miami", "U.S.A.",           130,  40, TEXT_R}, \
    {"Nassau", "Bahamas",         138,  46, TEXT_R}, \
    {"Panama City", "Panama",      90,  80, TEXT_R}, \
    {"Rio de Janeiro", "Brazil",  188, 160, TEXT_L}, \
    {"San Juan", "Puerto Rico",   156,  70, TEXT_L}, \
    {"Tel Aviv", "Israel",        199,  95, TEXT_L}}

#define  EUROPE_CITY_LIST  { \
    {"Amsterdam", "Holland",       54,  96, TEXT_R}, \
    {"Washington", "D.C.",          1, 108, TEXT_R}, \
    {"Athens", "Greece",          138, 154, TEXT_R}, \
    {"Belgrade", "Yugoslavia",    120, 125, TEXT_R}, \
    {"Berlin", "Germany",          85,  85, TEXT_R}, \
    {"Budapest", "Hungary",       108, 100, TEXT_R}, \
    {"Geneva", "Switzerland",      64, 118, TEXT_R}, \
    {"Helsinki", "Finland",       125,  52, TEXT_R}, \
    {"London", "England",          42,  90, TEXT_R}, \
    {"Madrid", "Spain",            28, 138, TEXT_R}, \
    {"Moscow", "U.S.S.R.",        156,  69, TEXT_R}, \
    {"Paris", "France",            50, 100, TEXT_R}, \
    {"Prague", "Czechoslovakia",   96,  96, TEXT_R}, \
    {"Rome", "Italy",              88, 125, TEXT_R}, \
    {"Tel Aviv", "Israel",        175, 166, TEXT_L}, \
    {"Vienna", "Austria",          95, 106, TEXT_R}}

void Africa::populateCityList() {
  for (City c : AFRICA_CITY_LIST)  { cities.push_back(c); }
}

void America::populateCityList() {
  for (City c : AMERICA_CITY_LIST)  { cities.push_back(c); }
}

void Europe::populateCityList() {
  for (City c : EUROPE_CITY_LIST)  { cities.push_back(c); }
}
