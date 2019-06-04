#ifndef FARM_H
#define FARM_H

#include <string>
#include <vector>

class Farm {
public:
  Farm(std::vector<std::string> positions);
  const std::vector<std::string>& getPositions() const;

private:
  std::vector<std::string> positions;
};

#endif
