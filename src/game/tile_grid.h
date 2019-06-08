#ifndef TILE_GRID_H
#define TILE_GRID_H

#include <boost/optional.hpp>
#include "../tiles/placed_tile.h"

class TileGrid {
public:
  TileGrid();
  virtual ~TileGrid();

  boost::optional<PlacedTile> getTile(int x, int y) const;
  void placeTile(PlacedTile tile, int x, int y);

private:
  static const int INIT_GRID_DIM = 51;
  static const int GRID_DIM_EXPANSION = 50;

  int grid_dim;
  boost::optional<PlacedTile>* tiles;

  int getAdjustedCoordintate(int coordinate, int grid_dim) const;
  int getGameCoordintate(int coordinate) const;

  void expandGrid();
};

#endif
