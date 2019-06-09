#include <boost/optional.hpp>
#include "tile_grid.h"

TileGrid::TileGrid() :
  grid_dim(TileGrid::INIT_GRID_DIM),
  tiles(new boost::optional<PlacedTile>[this->grid_dim * this->grid_dim])
  {}

TileGrid::~TileGrid() {
  delete[] this->tiles;
}

boost::optional<PlacedTile> TileGrid::getTile(int x, int y) const {
  int adjusted_x = this->getAdjustedCoordintate(x, this->grid_dim);
  int adjusted_y = this->getAdjustedCoordintate(y, this->grid_dim);

  if (this->isAdjustedCoordinteInRange(adjusted_x) &&
    this->isAdjustedCoordinteInRange(adjusted_y)) {
      return this->tiles[adjusted_x * this->grid_dim + adjusted_y];
  } else {
    return boost::optional<PlacedTile>();
  }
}

void TileGrid::placeTile(PlacedTile tile, int x, int y) {
  int adjusted_x = this->getAdjustedCoordintate(x, this->grid_dim);
  int adjusted_y = this->getAdjustedCoordintate(y, this->grid_dim);

  // TODO: Verify placement is legal
  if (this->isAdjustedCoordinteInRange(adjusted_x) &&
    this->isAdjustedCoordinteInRange(adjusted_y)) {
      this->tiles[adjusted_x * this->grid_dim + adjusted_y] = tile;
  } else {
    this->expandGrid();
    this->placeTile(tile, x, y);
  }
}

int TileGrid::getAdjustedCoordintate(int coordinate, int grid_dim) const {
  int offset = (grid_dim - 1) / 2;
  return coordinate + offset;
}

int TileGrid::getGameCoordintate(int coordinate) const {
  int offset = (this->grid_dim - 1) / 2;
  return coordinate - offset;
}

bool TileGrid::isAdjustedCoordinteInRange(int coordinate) const {
  return coordinate >= 0 && coordinate < this->grid_dim;
}

void TileGrid::expandGrid() {
  int new_grid_dim = this->grid_dim + TileGrid::GRID_DIM_EXPANSION;
  boost::optional<PlacedTile>* new_tiles =
    new boost::optional<PlacedTile>[new_grid_dim * new_grid_dim];

  for (int x = 0; x < this->grid_dim; ++x) {
    for (int y = 0; y < this->grid_dim; ++y) {
      boost::optional<PlacedTile> tile = this->tiles[x * this->grid_dim + y];
      if (tile.is_initialized()) {
        int game_x = this->getGameCoordintate(x);
        int game_y = this->getGameCoordintate(y);

        int adjusted_x = this->getAdjustedCoordintate(game_x, new_grid_dim);
        int adjusted_y = this->getAdjustedCoordintate(game_y, new_grid_dim);

        new_tiles[adjusted_x * new_grid_dim + adjusted_y] = tile;
      }
    }
  }

  delete[] this->tiles;

  this->grid_dim = new_grid_dim;
  this->tiles = new_tiles;
}
