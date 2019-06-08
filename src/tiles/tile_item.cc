#include "tile_item.h"

TileItem::TileItem() : meeple(nullptr) {}

Meeple* TileItem::getMeeple() const {
  return this->meeple;
}

void TileItem::setMeeple(Meeple* meeple) {
  this->meeple->markPlaced();
  this->meeple = meeple;
}

void TileItem::removeMeeple() {
  this->meeple->markUnplaced();
  this->meeple = nullptr;
}
