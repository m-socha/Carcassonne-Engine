#ifndef PLACED_TILE_H
#define PLACED_TILE_H

#include "tile.h"

class PlacedTile {
public:

  PlacedTile(Tile tile, int rotation);

  bool operator==(const PlacedTile &placed_tile) const;

  Tile getTile() const;
  TileRotation getRotation() const;

  Tile getRotatedTile() const;

private:
  Tile tile;
  TileRotation rotation;
};

#endif
