#include "placed_tile.h"

PlacedTile::PlacedTile(Tile tile, int rotation)
  : tile(tile), rotation(static_cast<PlacedTile::Rotation>(rotation))
  {}

Tile PlacedTile::getTile() const {
  return this->tile;
}

PlacedTile::Rotation PlacedTile::getRotation() const {
  return this->rotation;
}
