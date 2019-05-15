#include "Lib/GridWorldPolicy.h"

#include <utility>
#include <vector>

namespace GridWorld {

std::vector<std::pair<DP::Probability, DP::Action>> RandomPolicy::Actions(
    DP::State state) const {
  // TODO(xiejw): Use model feasible actions.
  std::vector<std::pair<DP::Probability, DP::Action>> actions;
  actions.reserve(4);
  actions.push_back(std::make_pair(0.25, Action::up));
  actions.push_back(std::make_pair(0.25, Action::down));
  actions.push_back(std::make_pair(0.25, Action::left));
  actions.push_back(std::make_pair(0.25, Action::right));
  return actions;
}

}  // namespace GridWorld
