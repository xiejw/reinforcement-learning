#include <utility>
#include <vector>

#include "Lib/GridWorldPolicy.h"

namespace GridWorld {

std::vector<std::pair<DP::Probability, DP::Action>> RandomPolicy::Actions(
    DP::State state) const {
  std::vector<std::pair<DP::Probability, DP::Action>> actions;
  actions.reserve(4);
  actions.push_back(std::make_pair(0.25, Action::up));
  actions.push_back(std::make_pair(0.25, Action::down));
  actions.push_back(std::make_pair(0.25, Action::left));
  actions.push_back(std::make_pair(0.25, Action::right));
  return actions;
}

std::vector<std::pair<DP::Probability, DP::Action>> GreedyPolicy::Actions(
    DP::State state) const {
  if (actions_.get() == nullptr) return baseline_policy_->Actions(state);

  return std::vector<std::pair<DP::Probability, DP::Action>>{
      std::make_pair(1.0, actions_[state])};
}

bool GreedyPolicy::Adapt(DP::ValueFunction &value_function) {
  const int state_space_size = value_function.Size();
  std::unique_ptr<Action[]> new_actions{new Action[state_space_size]};
  bool changed = false;
  for (DP::State state = 0; state < state_space_size; ++state) {
    // TODO: Take action and get the expected result.
    new_actions[state] = Action::up;
  }
  return changed;
};

}  // namespace GridWorld
