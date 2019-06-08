#include "player.h"

using namespace std;

Player::Player(string name) : name(name) {
  Meeple meeple(this);
  meeples.insert(meeples.end(), Player::NUM_PLAYER_MEEPLES, meeple);
}

const string& Player::getName() const {
  return this->name;
}

Meeple* Player::getMeeple(int index) {
  Meeple& meeple = meeples.at(index);
  return &meeple;
}
