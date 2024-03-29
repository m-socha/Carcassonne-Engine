#ifndef GAME_H
#define GAME_H

#include "../players/player.h"
#include "tile_grid.h"

class Game {
public:
  Game(std::vector<Player*> players);
  virtual ~Game();

private:
  std::vector<Player*> players;
  TileGrid tile_grid;
};

#endif
