#include "meeple_placement_evaluation.h"

using namespace std;

bool isMeeplePlaced(const std::vector<TileItem>& item_sections) {
  return any_of(item_sections.begin(), item_sections.end(),
    [](const TileItem& item) {
      return item.getMeeple() != nullptr;
    }
  );
}

bool getNumMeeples(const std::vector<TileItem>& item_sections, const Player& player) {
  return count_if(item_sections.begin(), item_sections.end(),
    [player](const TileItem& item) {
      Meeple* meeple = item.getMeeple();
      return meeple != nullptr && *meeple->getPlayer() == player;
    }
  );
}
