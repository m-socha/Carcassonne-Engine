#include "legal_move_evaluation.h"

using namespace std;

static vector<boost::optional<PlacedTile>> get_adjacent_tiles(const TileGrid& grid, int x, int y) {
  return {
    grid.getTile(x - 1, y),
    grid.getTile(x + 1, y),
    grid.getTile(x, y - 1),
    grid.getTile(x, y + 1)
  };
}

static bool exists_adjacent_tile(const TileGrid& grid, int x, int y) {
  vector<boost::optional<PlacedTile>> adjacent_tiles = get_adjacent_tiles(grid, x, y);
  return std::any_of(adjacent_tiles.begin(), adjacent_tiles.end(),
    [](boost::optional<PlacedTile> tile){
      return tile.is_initialized();
    }
  );
}

bool is_placement_legal(const TileGrid& grid, PlacedTile tile, int x, int y) {
  return (exists_adjacent_tile(grid, x, y) || grid.isEmpty());
}
