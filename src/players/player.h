#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "meeple.h"

class Player {
public:
  Player(int id, std::string name);

  bool operator==(const Player& player) const;

  const int getId() const;
  const std::string& getName() const;
  Meeple* getMeeple(int index);

private:
  static const int NUM_PLAYER_MEEPLES = 7;

  int id;
  std::string name;
  std::vector<Meeple> meeples;
};

#endif
