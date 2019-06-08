#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "meeple.h"

class Player {
public:
  Player(std::string name);
  const std::string& getName() const;
  Meeple* getMeeple(int index);

private:
  static const int NUM_PLAYER_MEEPLES = 7;

  std::string name;
  std::vector<Meeple> meeples;
};

#endif
