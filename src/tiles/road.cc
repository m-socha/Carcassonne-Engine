#include "road.h"

using namespace std;

Road::Road(vector<int> positions) : FourSideItem(positions) {}

bool Road::operator==(const Road &road) const {
  return this->positions == road.positions;
}
