#include "Lib/GamblerProblemPolicy.h"

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace GamblerProblem {

std::vector<std::pair<DP::Probability, DP::Action>> RandomPolicy::Actions(
    DP::State state) const {
  const auto &feasible_actions = model_.FeasibleActions(state);
  assert(feasible_actions.size() > 0);

  const double probability = 1.0 / feasible_actions.size();

  std::vector<std::pair<DP::Probability, DP::Action>> actions;
  actions.reserve(feasible_actions.size());
  for (auto &action : feasible_actions)
    actions.push_back(std::make_pair(probability, action));

  return actions;
}

}  // namespace GamblerProblem
