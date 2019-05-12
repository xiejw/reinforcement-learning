#include <utility>
#include <vector>

#include "GridWorldPolicy.h"

namespace DP {

std::vector<std::pair<Probability, Action>> GridWorldRandomPolicy::Actions(
    State state) const {
  std::vector<std::pair<Probability, Action>> actions;
  actions.reserve(4);
  actions.push_back(std::make_pair(0.25, GridWorldAction::up));
  actions.push_back(std::make_pair(0.25, GridWorldAction::down));
  actions.push_back(std::make_pair(0.25, GridWorldAction::left));
  actions.push_back(std::make_pair(0.25, GridWorldAction::right));
  return actions;
}

}  // namespace DP
