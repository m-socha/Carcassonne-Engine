#ifndef MEEPLE_H
#define MEEPLE_H

class Player;

class Meeple {
public:
  Meeple(Player* player);
  Player* getPlayer() const;

  bool isPlaced() const;
  void markPlaced();
  void markUnplaced();

private:
  Player* player;
  bool placed;
};

#endif
