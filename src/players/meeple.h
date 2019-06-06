#ifndef MEEPLE_H
#define MEEPLE_H

class Player;

class Meeple {
public:
  Meeple(Player* player);
  Player* getPlayer() const;

private:
  Player* player;
};

#endif
