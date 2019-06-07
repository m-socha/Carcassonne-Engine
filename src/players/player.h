#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "meeple.h"

class Player {
public:
  Player();
  virtual ~Player();

private:
  static const int NUM_PLAYER_MEEPLES = 7;
  std::vector<Meeple*> meeples;
};

#endif
