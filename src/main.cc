#include "parsing/parse_tiles.h"

using namespace std;

int main(int argc, char** argv) {
  vector<Tile> tiles = parse_tiles("tiles/standard_game.json");

  return 0;
}
