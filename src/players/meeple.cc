#include "meeple.h"

Meeple::Meeple(Player* player) : player(player) {}

Player* Meeple::getPlayer() const {
  return this->player;
}
