#ifndef LEGAL_MOVE_EVALUATION_H
#define LEGAL_MOVE_EVALUATION_H

#include "../game/tile_grid.h"

bool is_placement_legal(const TileGrid& grid, PlacedTile tile, int x, int y);

#endif
