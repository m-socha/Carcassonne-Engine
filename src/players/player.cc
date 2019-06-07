#include "player.h"

using namespace std;

Player::Player() {
  for (int i = 0; i < Player::NUM_PLAYER_MEEPLES; ++i) {
    Meeple* meeple = new Meeple(this);
    meeples.push_back(meeple);
  }
}

Player::~Player() {
  for(vector<Meeple*>::iterator it = meeples.begin(); it != meeples.end(); ++it) {
    Meeple* meeple = *it;
    delete meeple;
  }
}
