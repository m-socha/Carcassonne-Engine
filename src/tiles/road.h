#ifndef ROAD_H
#define ROAD_H

#include "four_side_item.h"

class Road : public FourSideItem {
public:
  Road(std::vector<int> positions);

  bool operator==(const Road &road) const;
};

#endif
