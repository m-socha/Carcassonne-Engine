#include "placed_tile.h"

PlacedTile::PlacedTile(Tile tile, int rotation)
  : tile(tile), rotation(static_cast<PlacedTile::Rotation>(rotation))
  {}

bool PlacedTile::operator==(const PlacedTile &placed_tile) const {
  return this->tile == placed_tile.tile &&
    this->rotation == placed_tile.rotation;
}

Tile PlacedTile::getTile() const {
  return this->tile;
}

PlacedTile::Rotation PlacedTile::getRotation() const {
  return this->rotation;
}
