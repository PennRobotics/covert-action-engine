#ifndef CA_DISCOVER_H
#define CA_DISCOVER_H

/// #include "../gfx/gfx.h"

/* Iterate through info potentially discoverable through scans and info already discovered */
/* Perhaps guard level of known locations is linked to activity score? */



uint16_t font_height = 8;
uint16_t min_score = 0;
uint16_t max_score = 36;
uint16_t bar_width = 4 + score;
uint16_t bar_height = font_height - 2;

render_bg(Color::BLUE);

render_text(90, 4, "Activity Report Summary", Color::WHITE);

uint16_t from_top = 16;
for (auto& city : theater->cities) {
  bar_width = get_city_score(city);
  render_text(1, from_top, city.name, DARKCYAN);
  render_bar(81, from_top, bar_width, bar_height, CYAN);
  from_top += 8;
}

from_top = 16;
for (auto& org : theater->orgs) {
  bar_width = get_org_score(org);
  render_text(160, from_top, org.abrv, RED);
  render_bar(240, from_top, bar_width, bar_height, YELLOW);
  from_top += 8;
}

uint16_t get_city_score(auto/*TODO*/ city) {
  // TODO: iterator-sum for org guard level in a city
  // TODO: iterator-sum for local scan data in a city
    return -1;
}

uint16_t get_org_score(auto/*TODO*/ org) {
  // TODO: iterator-sum for guard level in each city with a known hideout
  // TODO: iterator-sum for local scan data for each city in an org
  return -1;
}

#endif
