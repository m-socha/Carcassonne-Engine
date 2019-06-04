#include "farm.h"

using namespace std;

Farm::Farm(vector<string> positions) {
  this->positions = positions;
}

const vector<string>& Farm::getPositions() const {
  return this->positions;
}
