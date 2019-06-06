#ifndef PLACED_TILE_H
#define PLACED_TILE_H

#include "tile.h"

class PlacedTile {
public:
  enum Rotation : int {
    ONE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4
  };

  PlacedTile(Tile tile, int rotation);
  Tile getTile() const;
  Rotation getRotation() const;

private:
  Tile tile;
  Rotation rotation;
};

#endif
