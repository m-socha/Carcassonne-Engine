#include "../../catch.hpp"
#include "../tile_grid.h"

using namespace std;

TEST_CASE("Empty Tile Uninitialized") {
  TileGrid tile_grid;
  boost::optional<PlacedTile> grid_tile = tile_grid.getTile(0, 0);
  REQUIRE_FALSE(grid_tile.is_initialized());
}

TEST_CASE("Out of Range Tile Uninitialized") {
  TileGrid tile_grid;
  boost::optional<PlacedTile> grid_tile = tile_grid.getTile(-200, 300);
  REQUIRE_FALSE(grid_tile.is_initialized());
}

TEST_CASE("Simple Tile Placement") {
  vector<City> cities;
  City city = City({1}, false);
  cities.push_back(city);

  vector<Road> roads;
  Road road = Road({2, 4});
  roads.push_back(road);

  vector<Farm> farms;
  Farm farm = Farm({"b", "h"});
  farms.push_back(farm);
  farm = Farm({"c", "d", "e", "f"});
  farms.push_back(farm);

  Tile tile(cities, roads, farms, false);
  PlacedTile placed_tile(tile, PlacedTile::Rotation::ONE);

  TileGrid tile_grid;
  tile_grid.placeTile(placed_tile, -5, 11);
  boost::optional<PlacedTile> grid_tile = tile_grid.getTile(-5, 11);

  REQUIRE(grid_tile.is_initialized());
  REQUIRE(grid_tile.get() == placed_tile);
}

TEST_CASE("Tile Placement Triggering Expansion") {
  vector<City> cities;
  vector<Road> roads;
  vector<Farm> farms;
  Farm farm = Farm({"a", "b", "c", "d", "e", "f", "g", "h"});
  farms.push_back(farm);

  Tile tile(cities, roads, farms, false);
  PlacedTile placed_tile(tile, PlacedTile::Rotation::ONE);

  TileGrid tile_grid;
  for (int x = 0; x < 200; ++x) {
    tile_grid.placeTile(placed_tile, x, 0);
  }

  for (int x = 0; x < 200; ++x) {
    boost::optional<PlacedTile> grid_tile = tile_grid.getTile(x, 0);
    REQUIRE(grid_tile.is_initialized());
  }
}
