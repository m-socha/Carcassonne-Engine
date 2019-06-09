#ifndef CLOISTER_H
#define CLOISTER_H

#include "tile_item.h"

class Cloister : public TileItem {
public:
  Cloister();

  bool operator==(const Cloister &cloister) const;
};

#endif
