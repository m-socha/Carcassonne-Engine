#include <algorithm>
#include "four_side_item.h"

using namespace std;

FourSideItem::FourSideItem(vector<int> positions) {
  transform(positions.begin(), positions.end(),
    back_inserter(this->positions),
    [](int i) -> FourSideItem::Position {
      return static_cast<FourSideItem::Position>(i);
    });
}

const vector<FourSideItem::Position>& FourSideItem::getPositions() const {
  return this->positions;
}
