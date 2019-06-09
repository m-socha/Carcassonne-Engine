#include "city.h"

City::City(std::vector<int> positions, bool has_shield) :
  FourSideItem(positions), has_shield(has_shield) {}

bool City::operator==(const City &city) const {
  return this->positions == city.positions &&
    this->has_shield == city.has_shield;
}

bool City::hasShield() const {
  return this->has_shield;
}
