#include "placed_tile.h"

using namespace std;

PlacedTile::PlacedTile(Tile tile, int rotation)
  : tile(tile), rotation(static_cast<TileRotation>(rotation))
  {}

bool PlacedTile::operator==(const PlacedTile &placed_tile) const {
  return this->tile == placed_tile.tile &&
    this->rotation == placed_tile.rotation;
}

Tile PlacedTile::getTile() const {
  return this->tile;
}

TileRotation PlacedTile::getRotation() const {
  return this->rotation;
}

Tile PlacedTile::getRotatedTile() const {
  vector<City> rotated_cities = this->tile.getCities();
  for_each(rotated_cities.begin(), rotated_cities.end(),
    [this](City& city) {
      city.rotate(this->rotation);
    }
  );

  vector<Road> rotated_roads = this->tile.getRoads();
  for_each(rotated_roads.begin(), rotated_roads.end(),
    [this](Road& road) {
      road.rotate(this->rotation);
    }
  );

  vector<Farm> rotated_farms = this->tile.getFarms();
  for_each(rotated_farms.begin(), rotated_farms.end(),
    [this](Farm& farm) {
      farm.rotate(this->rotation);
    }
  );

  boost::optional<Cloister> rotated_cloister = this->tile.getCloister();

  return Tile(rotated_cities, rotated_roads, rotated_farms,
    rotated_cloister.is_initialized());
}
