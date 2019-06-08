#include "game.h"

using namespace std;

Game::Game(vector<Player*> players) : players(players) {}

Game::~Game() {
  for (vector<Player*>::iterator it = players.begin(); it != players.end(); ++it) {
    Player* player = *it;
    delete player;
  }
}
