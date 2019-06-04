#ifndef TILE_H
#define TILE_H

#include "city.h"
#include "road.h"
#include "farm.h"

class Tile {
public:
  Tile(std::vector<City> cities, std::vector<Road> roads, std::vector<Farm> farms, bool has_cloister);
  const std::vector<City>& getCities() const;
  const std::vector<Road>& getRoads() const;
  const std::vector<Farm>& getFarms() const;
  bool hasCloister() const;

private:
  std::vector<City> cities;
  std::vector<Road> roads;
  std::vector<Farm> farms;
  bool has_cloister;
};

#endif
