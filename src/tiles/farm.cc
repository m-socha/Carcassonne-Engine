#include <algorithm>
#include "farm.h"

using namespace std;

Farm::Farm(vector<string> positions) {
  transform(positions.begin(), positions.end(),
    back_inserter(this->positions),
    [](string s) -> Farm::Position {
      return static_cast<Farm::Position>(s[0]);
    });
}

const vector<Farm::Position>& Farm::getPositions() const {
  return this->positions;
}