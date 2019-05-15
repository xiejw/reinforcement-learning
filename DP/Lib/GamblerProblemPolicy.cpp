#include "Lib/GamblerProblemPolicy.h"

#include <algorithm>
#include <cassert>
#include <iostream>
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

std::vector<std::pair<DP::Probability, DP::Action>> GreedyPolicy::Actions(
    DP::State state) const {
  if (actions_.get() == nullptr) return baseline_policy_->Actions(state);

  return std::vector<std::pair<DP::Probability, DP::Action>>{
      std::make_pair(1.0, actions_[state])};
}

bool GreedyPolicy::Adapt(DP::ValueFunction &value_function) {
  const int state_space_size = value_function.Size();
  const double *const values = value_function.Values();
  std::unique_ptr<DP::Action[]> new_actions{new DP::Action[state_space_size]};
  bool changed = false;

  // Iterate on all states. For each one, find the action with the maximum
  // expected value.
  for (DP::State state = 0; state < state_space_size; ++state) {
    if (model_.IsTerminalState(state)) {
      // We choose the na (n/a) for terminal state.
      new_actions[state] = DP::SpecialAction::na;
    } else {
      bool first_time_visit = true;
      double max_value = 0.0;
      // Maintain the same action search order to ensure stable greed selection.
      for (auto &action : model_.FeasibleActions(state)) {
        double new_value = 0.0;
        for (auto &transition : model_.Transition(state, action)) {
          auto &reward = std::get<0>(transition);
          auto &state_probability = std::get<1>(transition);
          auto &new_state = std::get<2>(transition);
          new_value += state_probability * (reward + values[new_state]);
        }

        // Bookkeeping.
        if (first_time_visit || new_value > max_value) {
          first_time_visit = false;
          max_value = new_value;
          new_actions[state] = action;
        }
      }
    }
    if (actions_.get() == nullptr || new_actions[state] != actions_[state])
      changed = true;
  }
  if (changed) actions_.swap(new_actions);
  return changed;
};

}  // namespace GamblerProblem
