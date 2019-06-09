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

void FourSideItem::rotate(TileRotation rotation) {
  for_each(this->positions.begin(), this->positions.end(),
    [rotation](FourSideItem::Position& pos) {
      int new_pos = (pos + rotation);
      if (new_pos > 4) {
        new_pos -= 4;
      }
      pos = static_cast<FourSideItem::Position>(new_pos);
    }
  );
}
