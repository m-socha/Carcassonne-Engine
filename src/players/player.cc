#include "player.h"

using namespace std;

Player::Player(int id, string name) : id(id), name(name) {
  Meeple meeple(this);
  meeples.insert(meeples.end(), Player::NUM_PLAYER_MEEPLES, meeple);
}

bool Player::operator==(const Player& player) const {
  return this->id == player.id;
}

const int Player::getId() const {
  return this->id;
}

const string& Player::getName() const {
  return this->name;
}

Meeple* Player::getMeeple(int index) {
  Meeple& meeple = meeples.at(index);
  return &meeple;
}
