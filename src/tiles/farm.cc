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

bool Farm::operator==(const Farm &farm) const {
  return this->positions == farm.positions;
}

const vector<Farm::Position>& Farm::getPositions() const {
  return this->positions;
}

void Farm::rotate(TileRotation rotation) {
  for_each(this->positions.begin(), this->positions.end(),
    [rotation](Farm::Position& pos) {
      char new_pos = pos + rotation * 2;
      if (new_pos > 'h') {
        new_pos -= 8;
      }
      pos = static_cast<Farm::Position>(new_pos);
    }
  );
}
