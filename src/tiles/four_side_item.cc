#include "four_side_item.h"

using namespace std;

FourSideItem::FourSideItem(vector<int> positions) {
  this->positions = positions;
}

const vector<int>& FourSideItem::getPositions() const {
  return this->positions;
}
