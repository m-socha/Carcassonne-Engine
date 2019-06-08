#include "game.h"

using namespace std;

Game::Game(vector<Player*> players) : players(players) {}

Game::~Game() {
  for (vector<Player*>::iterator it = players.begin(); it != it; ++it) {
    Player* player = *it;
    delete player;
  }
}
