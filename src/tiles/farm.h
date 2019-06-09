#ifndef FARM_H
#define FARM_H

#include <string>
#include <vector>
#include "tile_item.h"

class Farm : public TileItem {
public:
  enum Position : char {
    A = 'a',
    B = 'b',
    C = 'c',
    D = 'd',
    E = 'e',
    F = 'f',
    G = 'g',
    H = 'h'
  };

  Farm(std::vector<std::string> positions);

  bool operator==(const Farm &farm) const;

  const std::vector<Position>& getPositions() const;

private:
  std::vector<Position> positions;
};

#endif
