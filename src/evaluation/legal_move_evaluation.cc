#include "legal_move_evaluation.h"

static bool exists_adjacent_tile(const TileGrid& grid, int x, int y) {
  boost::optional<PlacedTile> adjacent_tile = grid.getTile(x - 1, y);
  if (!adjacent_tile.is_initialized()) {
    return false;
  }

  adjacent_tile = grid.getTile(x + 1, y);
  if (!adjacent_tile.is_initialized()) {
    return false;
  }

  adjacent_tile = grid.getTile(x, y - 1);
  if (!adjacent_tile.is_initialized()) {
    return false;
  }

  adjacent_tile = grid.getTile(x, y + 1);
  if (!adjacent_tile.is_initialized()) {
    return false;
  }

  return true;
}

bool is_placement_legal(const TileGrid& grid, PlacedTile tile, int x, int y) {
  return (exists_adjacent_tile(grid, x, y) || grid.isEmpty());
}
