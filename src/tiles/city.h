#ifndef CITY_H
#define CITY_H

#include "four_side_item.h"

class City : public FourSideItem {
public:
  City(std::vector<int> positions, bool has_shield);

  bool operator==(const City &city) const;

  bool hasShield() const;

private:
  bool has_shield;
};

#endif
