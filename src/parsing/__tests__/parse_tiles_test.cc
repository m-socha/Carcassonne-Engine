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
    REQUIRE(city.getMeeple() == nullptr);
    vector<FourSideItem::Position> city_positions = city.getPositions();
    REQUIRE(city_positions.size() == 1);
    REQUIRE(city_positions.at(0) == FourSideItem::Position::ONE);
    REQUIRE_FALSE(city.hasShield());

    vector<Road> roads = tile.getRoads();
    REQUIRE(roads.size() == 1);
    Road road = roads.at(0);
    REQUIRE(road.getMeeple() == nullptr);
    vector<FourSideItem::Position> road_positions = road.getPositions();
    REQUIRE(road_positions.size() == 2);
    REQUIRE(road_positions.at(0) == FourSideItem::Position::TWO);
    REQUIRE(road_positions.at(1) == FourSideItem::Position::FOUR);

    vector<Farm> farms = tile.getFarms();
    REQUIRE(farms.size() == 2);
    Farm farm = farms.at(0);
    REQUIRE(farm.getMeeple() == nullptr);
    vector<Farm::Position> farm_positions = farm.getPositions();
    REQUIRE(farm_positions.size() == 2);
    REQUIRE(farm_positions.at(0) == Farm::Position::B);
    REQUIRE(farm_positions.at(1) == Farm::Position::H);
    farm = farms.at(1);
    REQUIRE(farm.getMeeple() == nullptr);
    farm_positions = farm.getPositions();
    REQUIRE(farm_positions.size() == 4);
    REQUIRE(farm_positions.at(0) ==  Farm::Position::C);
    REQUIRE(farm_positions.at(1) ==  Farm::Position::D);
    REQUIRE(farm_positions.at(2) ==  Farm::Position::E);
    REQUIRE(farm_positions.at(3) ==  Farm::Position::F);

    REQUIRE_FALSE(tile.hasCloister());
  }

  for (int i = 4; i < 6; ++i) {
    Tile tile = tiles.at(i);

    vector<City> cities = tile.getCities();
    REQUIRE(cities.size() == 0);

    vector<Road> roads = tile.getRoads();
    REQUIRE(roads.size() == 1);
    Road road = roads.at(0);
    REQUIRE(road.getMeeple() == nullptr);
    vector<FourSideItem::Position> road_positions = road.getPositions();
    REQUIRE(road_positions.size() == 1);
    REQUIRE(road_positions.at(0) == FourSideItem::Position::THREE);

    vector<Farm> farms = tile.getFarms();
    REQUIRE(farms.size() == 1);
    Farm farm = farms.at(0);
    REQUIRE(farm.getMeeple() == nullptr);
    vector<Farm::Position> farm_positions = farm.getPositions();
    REQUIRE(farm_positions.size() == 8);
    REQUIRE(farm_positions.at(0) == Farm::Position::A);
    REQUIRE(farm_positions.at(1) == Farm::Position::B);
    REQUIRE(farm_positions.at(2) == Farm::Position::C);
    REQUIRE(farm_positions.at(3) == Farm::Position::D);
    REQUIRE(farm_positions.at(4) == Farm::Position::E);
    REQUIRE(farm_positions.at(5) == Farm::Position::F);
    REQUIRE(farm_positions.at(6) == Farm::Position::G);
    REQUIRE(farm_positions.at(7) == Farm::Position::H);

    REQUIRE(tile.hasCloister());
  }
}
