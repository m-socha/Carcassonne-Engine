#ifndef TILE_ITEM_H
#define TILE_ITEM_H

#include "../players/meeple.h"

class TileItem {
public:
  TileItem();
  Meeple* getMeeple() const;
  void setMeeple(Meeple* meeple);
  void removeMeeple();

private:
  Meeple* meeple;
};

#endif
