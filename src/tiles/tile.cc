#include "tile.h"

using namespace std;

Tile::Tile(vector<City> cities, vector<Road> roads, vector<Farm> farms, bool has_cloister)
  : cities(cities), roads(roads), farms(farms) {
    if (has_cloister) {
      this->cloister = Cloister();
    }
  }

bool Tile::operator==(const Tile &tile) const {
  return this->cities == tile.cities &&
    this->roads == tile.roads &&
    this->farms == tile.farms &&
    this->cloister == tile.cloister;
}

const vector<City>& Tile::getCities() const {
  return this->cities;
}

const vector<Road>& Tile::getRoads() const {
  return this->roads;
}

const vector<Farm>& Tile::getFarms() const {
  return this->farms;
}

const boost::optional<Cloister> Tile::getCloister() const {
  return this->cloister;
}
