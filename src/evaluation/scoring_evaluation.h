#ifndef SCORING_H
#define SCORING_H

#include "../game/tile_grid.h"

int getCityScore(const std::vector<City>& city_sections, bool is_complete);
int getRoadScore(const std::vector<Road>& road_sections);
int getCloisterScore(const TileGrid& grid, int x, int y);

#endif
