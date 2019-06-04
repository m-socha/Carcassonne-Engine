#include <fstream>
#include "parse_tiles.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

vector<Tile> parse_tiles(string file_name) {
  ifstream ifs(file_name);
  json j;
  ifs >> j;

  vector<Tile> tiles;
  for (json::iterator it = j.begin(); it != j.end(); ++it) {
    json tileset_json = *it;

    json cities_json = tileset_json["cities"];
    vector<City> cities;
    for (json::iterator city_it = cities_json.begin(); city_it != cities_json.end(); ++city_it) {
      json city_json = *city_it;
      vector<int> positions = city_json["positions"];
      bool has_shield = (city_json["shield"] == "Y");

      City city(positions, has_shield);
      cities.push_back(city);
    }

    json roads_json = tileset_json["roads"];
    vector<Road> roads;
    for (json::iterator road_it = roads_json.begin(); road_it != roads_json.end(); ++road_it) {
      json road_json = *road_it;
      vector<int> positions = road_json["positions"];

      Road road(positions);
      roads.push_back(road);
    }

    json farms_json = tileset_json["farms"];
    vector<Farm> farms;
    for (json::iterator farm_it = farms_json.begin(); farm_it != farms_json.end(); ++farm_it) {
      json farm_json = *farm_it;
      vector<string> positions = farm_json["positions"];

      Farm farm(positions);
      farms.push_back(farm);
    }

    bool has_cloister = (tileset_json["cloister"] == "Y");

    int quantity = tileset_json["quantity"];

    Tile tile(cities, roads, farms, has_cloister);
    tiles.insert(tiles.end(), quantity, tile);
  }

  return tiles;
}
