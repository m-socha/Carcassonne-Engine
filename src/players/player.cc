#include "player.h"

using namespace std;

Player::Player() {
  Meeple meeple(this);
  meeples.insert(meeples.end(), Player::NUM_PLAYER_MEEPLES, meeple);
}

Meeple* Player::getMeeple(int index) {
  Meeple& meeple = meeples.at(index);
  return &meeple;
}
