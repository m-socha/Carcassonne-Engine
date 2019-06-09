#include "../../catch.hpp"
#include "../placed_tile.h"

using namespace std;

TEST_CASE("Tile Rotation Test") {
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

  PlacedTile placed_tile(tile, TileRotation::ZERO);
  Tile rotated_tile = placed_tile.getRotatedTile();
  Tile rotated_zero_tile = tile;
  REQUIRE(rotated_tile == rotated_zero_tile);

  placed_tile = PlacedTile(tile, TileRotation::ONE);
  rotated_tile = placed_tile.getRotatedTile();
  vector<City> rotated_one_cities;
  rotated_one_cities.push_back(City({2}, false));
  vector<Road> rotated_one_roads;
  rotated_one_roads.push_back(Road({3, 1}));
  vector<Farm> rotated_one_farms;
  rotated_one_farms.push_back(Farm({"d", "b"}));
  rotated_one_farms.push_back(Farm({"e", "f", "g", "h"}));
  Tile rotated_one_tile(rotated_one_cities, rotated_one_roads, rotated_one_farms, false);
  REQUIRE(rotated_tile == rotated_one_tile);

  placed_tile = PlacedTile(tile, TileRotation::TWO);
  rotated_tile = placed_tile.getRotatedTile();
  vector<City> rotated_two_cities;
  rotated_two_cities.push_back(City({3}, false));
  vector<Road> rotated_two_roads;
  rotated_two_roads.push_back(Road({4, 2}));
  vector<Farm> rotated_two_farms;
  rotated_two_farms.push_back(Farm({"f", "d"}));
  rotated_two_farms.push_back(Farm({"g", "h", "a", "b"}));
  Tile rotated_two_tile(rotated_two_cities, rotated_two_roads, rotated_two_farms, false);
  REQUIRE(rotated_tile == rotated_two_tile);

  placed_tile = PlacedTile(tile, TileRotation::THREE);
  rotated_tile = placed_tile.getRotatedTile();
  vector<City> rotated_three_cities;
  rotated_three_cities.push_back(City({4}, false));
  vector<Road> rotated_three_roads;
  rotated_three_roads.push_back(Road({1, 3}));
  vector<Farm> rotated_three_farms;
  rotated_three_farms.push_back(Farm({"h", "f"}));
  rotated_three_farms.push_back(Farm({"a", "b", "c", "d"}));
  Tile rotated_three_tile(rotated_three_cities, rotated_three_roads, rotated_three_farms, false);
  REQUIRE(rotated_tile == rotated_three_tile);
}
