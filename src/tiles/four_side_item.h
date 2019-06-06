#ifndef FOUR_SIDE_ITEM_H
#define FOUR_SIDE_ITEM_H

#include <vector>

class FourSideItem {
public:
  enum Position : int {
    ONE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
  };

  FourSideItem(std::vector<int> positions);
  const std::vector<Position>& getPositions() const;

private:
  std::vector<Position> positions;
};

#endif
