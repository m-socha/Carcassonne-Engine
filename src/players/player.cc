#include "player.h"

Player::Player() {
  Meeple meeple(this);
  meeples.insert(meeples.end(), Player::NUM_PLAYER_MEEPLES, meeple);
}
