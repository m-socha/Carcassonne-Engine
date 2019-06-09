#include "../../catch.hpp"
#include "../tile_grid.h"

using namespace std;

TEST_CASE("Test Grid Empty") {
  TileGrid tile_grid;
  REQUIRE(tile_grid.isEmpty());

  vector<City> cities;
  vector<Road> roads;
  vector<Farm> farms;
  Farm farm = Farm({"a", "b", "c", "d", "e", "f", "g", "h"});
  farms.push_back(farm);

  Tile tile(cities, roads, farms, false);
  PlacedTile placed_tile(tile, TileRotation::ZERO);

  tile_grid.placeTile(placed_tile, -5, 11);
  REQUIRE_FALSE(tile_grid.isEmpty());
}
