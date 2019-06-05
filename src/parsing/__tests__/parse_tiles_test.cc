#define CATCH_CONFIG_MAIN

#include "../../catch.hpp"
#include "../parse_tiles.h"

using namespace std;

TEST_CASE("Valid Tile Parse") {
  vector<Tile> tiles = parse_tiles("src/parsing/__tests__/valid_tiles.json");
  REQUIRE(tiles.size() == 6);

  for (int i = 0; i < 4; ++i) {
    Tile tile = tiles.at(i);

    vector<City> cities = tile.getCities();
    REQUIRE(cities.size() == 1);
    City city = cities.at(0);
    vector<int> city_positions = city.getPositions();
    REQUIRE(city_positions.size() == 1);
    REQUIRE(city_positions.at(0) == 1);
    REQUIRE_FALSE(city.hasShield());

    vector<Road> roads = tile.getRoads();
    REQUIRE(roads.size() == 1);
    Road road = roads.at(0);
    vector<int> road_positions = road.getPositions();
    REQUIRE(road_positions.size() == 2);
    REQUIRE(road_positions.at(0) == 2);
    REQUIRE(road_positions.at(1) == 4);

    vector<Farm> farms = tile.getFarms();
    REQUIRE(farms.size() == 2);
    Farm farm = farms.at(0);
    vector<string> farm_positions = farm.getPositions();
    REQUIRE(farm_positions.size() == 2);
    REQUIRE(farm_positions.at(0) == "b");
    REQUIRE(farm_positions.at(1) == "h");
    farm = farms.at(1);
    farm_positions = farm.getPositions();
    REQUIRE(farm_positions.size() == 4);
    REQUIRE(farm_positions.at(0) == "c");
    REQUIRE(farm_positions.at(1) == "d");
    REQUIRE(farm_positions.at(2) == "e");
    REQUIRE(farm_positions.at(3) == "f");

    REQUIRE_FALSE(tile.hasCloister());
  }

  for (int i = 4; i < 6; ++i) {
    Tile tile = tiles.at(i);

    vector<City> cities = tile.getCities();
    REQUIRE(cities.size() == 0);

    vector<Road> roads = tile.getRoads();
    REQUIRE(roads.size() == 1);
    Road road = roads.at(0);
    vector<int> road_positions = road.getPositions();
    REQUIRE(road_positions.size() == 1);
    REQUIRE(road_positions.at(0) == 3);

    vector<Farm> farms = tile.getFarms();
    REQUIRE(farms.size() == 1);
    Farm farm = farms.at(0);
    vector<string> farm_positions = farm.getPositions();
    REQUIRE(farm_positions.size() == 8);
    REQUIRE(farm_positions.at(0) == "a");
    REQUIRE(farm_positions.at(1) == "b");
    REQUIRE(farm_positions.at(2) == "c");
    REQUIRE(farm_positions.at(3) == "d");
    REQUIRE(farm_positions.at(4) == "e");
    REQUIRE(farm_positions.at(5) == "f");
    REQUIRE(farm_positions.at(6) == "g");
    REQUIRE(farm_positions.at(7) == "h");

    REQUIRE(tile.hasCloister());
  }
}
