#include "scoring_evaluation.h"

using namespace std;

int getCityScore(const vector<City>& city_sections, bool is_complete) {
  int num_shields = count_if(city_sections.begin(), city_sections.end(),
    [](const City& city) {
      return city.hasShield();
    }
  );

  int multiplier = is_complete ? 2 : 1;
  return (city_sections.size() + num_shields) * multiplier;
}

int getRoadScore(const vector<Road>& road_sections) {
  return road_sections.size();
}

int getCloisterScore(const TileGrid& grid, int x, int y) {
  vector<boost::optional<PlacedTile>> surrounding_tiles = {
    grid.getTile(x, y + 1),
    grid.getTile(x + 1, y + 1),
    grid.getTile(x + 1, y),
    grid.getTile(x + 1, y - 1),
    grid.getTile(x, y - 1),
    grid.getTile(x - 1, y - 1),
    grid.getTile(x - 1, y),
    grid.getTile(x - 1, y + 1),
  };

  int num_surrounding_tiles = count_if(surrounding_tiles.begin(), surrounding_tiles.end(),
    [](const boost::optional<PlacedTile>& tile) {
      return tile.is_initialized();
    }
  );

  return num_surrounding_tiles + 1;
}
