#ifndef MEEPLE_PLACEMENT_EVALUATION_H
#define MEEPLE_PLACEMENT_EVALUATION_H

#include "../game/tile_grid.h"
#include "../players/player.h"

bool isMeeplePlaced(const std::vector<TileItem>& item_sections);
bool getNumMeeples(const std::vector<TileItem>& item_sections, const Player& player);

#endif
