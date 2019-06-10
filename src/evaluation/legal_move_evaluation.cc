#include "legal_move_evaluation.h"

using namespace std;

static vector<boost::optional<PlacedTile>> get_adjacent_tiles(const TileGrid& grid, int x, int y) {
  return {
    grid.getTile(x, y + 1),
    grid.getTile(x + 1, y),
    grid.getTile(x, y - 1),
    grid.getTile(x - 1, y)
  };
}

static bool exists_adjacent_tile(const TileGrid& grid, int x, int y) {
  vector<boost::optional<PlacedTile>> adjacent_tiles = get_adjacent_tiles(grid, x, y);
  return any_of(adjacent_tiles.begin(), adjacent_tiles.end(),
    [](const boost::optional<PlacedTile>& tile) {
      return tile.is_initialized();
    }
  );
}

static bool tile_side_pair_matches(Tile tile, boost::optional<PlacedTile> adj_tile,
  FourSideItem::Position tile_side, FourSideItem::Position adj_tile_side) {
  if (!adj_tile.is_initialized()) {
    return true;
  }

  vector<City> cities = tile.getCities();
  if (any_of(cities.begin(), cities.end(), [tile_side](const City& city) {
    vector<FourSideItem::Position> positions = city.getPositions();
    return find(positions.begin(), positions.end(), tile_side) != positions.end();
  })) {
    vector<City> adj_cities = adj_tile->getRotatedTile().getCities();
    if (!any_of(adj_cities.begin(), adj_cities.end(), [adj_tile_side](const City& city) {
      vector<FourSideItem::Position> positions = city.getPositions();
      return find(positions.begin(), positions.end(), adj_tile_side) != positions.end();
    })) {
      return false;
    }
  }

  vector<Road> roads = tile.getRoads();
  if (any_of(roads.begin(), roads.end(), [tile_side](const Road& road) {
    vector<FourSideItem::Position> positions = road.getPositions();
    return find(positions.begin(), positions.end(), tile_side) != positions.end();
  })) {
    vector<Road> adj_roads = adj_tile->getRotatedTile().getRoads();
    if (!any_of(adj_roads.begin(), adj_roads.end(), [adj_tile_side](const Road& road) {
      vector<FourSideItem::Position> positions = road.getPositions();
      return find(positions.begin(), positions.end(), adj_tile_side) != positions.end();
    })) {
      return false;
    }
  }

  return true;
}

static bool tile_sides_match(const TileGrid& grid, PlacedTile tile, int x, int y) {
  Tile rotated_tile = tile.getRotatedTile();
  boost::optional<PlacedTile> above_tile = grid.getTile(x, y + 1);
  boost::optional<PlacedTile> right_tile = grid.getTile(x + 1, y);
  boost::optional<PlacedTile> below_tile = grid.getTile(x, y - 1);
  boost::optional<PlacedTile> left_tile = grid.getTile(x - 1, y);

  if (!tile_side_pair_matches(rotated_tile, above_tile, FourSideItem::Position::ONE, FourSideItem::Position::THREE)) {
    return false;
  }

  if (!tile_side_pair_matches(rotated_tile, right_tile, FourSideItem::Position::TWO, FourSideItem::Position::FOUR)) {
    return false;
  }

  if (!tile_side_pair_matches(rotated_tile, below_tile, FourSideItem::Position::THREE, FourSideItem::Position::ONE)) {
    return false;
  }

  if (!tile_side_pair_matches(rotated_tile, left_tile, FourSideItem::Position::FOUR, FourSideItem::Position::TWO)) {
    return false;
  }

  return true;
}

bool is_placement_legal(const TileGrid& grid, PlacedTile tile, int x, int y) {
  return (exists_adjacent_tile(grid, x, y) || grid.isEmpty()) &&
    tile_sides_match(grid, tile, x, y);
}
