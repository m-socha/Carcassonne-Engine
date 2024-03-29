#include "meeple.h"

Meeple::Meeple(Player* player) : player(player), placed(false) {}

Player* Meeple::getPlayer() const {
  return this->player;
}

bool Meeple::isPlaced() const {
  return this->placed;
}

void Meeple::markPlaced() {
  this->placed = true;
}

void Meeple::markUnplaced() {
  this->placed = false;
}
