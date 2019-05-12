#include <utility>
#include <vector>

#include "Policy.h"

namespace DP {

std::vector<std::pair<Probability, Action>> RandomPolicy::Actions(
    State state) const {
  std::vector<std::pair<Probability, Action>> actions;
  actions.reserve(4);
  actions.push_back(std::make_pair(0.25, Action::up));
  actions.push_back(std::make_pair(0.25, Action::down));
  actions.push_back(std::make_pair(0.25, Action::left));
  actions.push_back(std::make_pair(0.25, Action::right));
  return actions;
}

}  // namespace DP
