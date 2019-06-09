#ifndef TILE_H
#define TILE_H

#include <boost/optional.hpp>
#include "city.h"
#include "road.h"
#include "farm.h"
#include "cloister.h"

class Tile {
public:
  Tile(std::vector<City> cities, std::vector<Road> roads, std::vector<Farm> farms, bool has_cloister);

  bool operator==(const Tile &tile) const;

  const std::vector<City>& getCities() const;
  const std::vector<Road>& getRoads() const;
  const std::vector<Farm>& getFarms() const;
  const boost::optional<Cloister> getCloister() const;

private:
  std::vector<City> cities;
  std::vector<Road> roads;
  std::vector<Farm> farms;
  boost::optional<Cloister> cloister;
};

#endif
