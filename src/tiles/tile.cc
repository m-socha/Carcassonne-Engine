#include "tile.h"

using namespace std;

Tile::Tile(vector<City> cities, vector<Road> roads, vector<Farm> farms, bool has_cloister)
  : cities(cities), roads(roads), farms(farms), has_cloister(has_cloister) {}

const vector<City>& Tile::getCities() const {
  return this->cities;
}

const vector<Road>& Tile::getRoads() const {
  return this->roads;
}

const vector<Farm>& Tile::getFarms() const {
  return this->farms;
}

bool Tile::hasCloister() const {
  return this->has_cloister;
}
