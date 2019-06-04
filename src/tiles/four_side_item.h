#ifndef FOUR_SIDE_ITEM_H
#define FOUR_SIDE_ITEM_H

#include <vector>

class FourSideItem {
public:
  FourSideItem(std::vector<int> positions);
  const std::vector<int>& getPositions() const;

private:
  std::vector<int> positions;
};

#endif
