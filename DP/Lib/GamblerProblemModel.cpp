#include "Lib/GamblerProblemModel.h"

#include <cassert>

#include "Lib/Support/Error.h"

namespace GamblerProblem {

std::vector<std::tuple<DP::Reward, DP::Probability, DP::State>>
Model::Transition(DP::State state, DP::Action action) const {
  std::vector<std::tuple<DP::Reward, DP::Probability, DP::State>> returns;

  // Tail case. Reward is always zero.
  returns.push_back(std::make_tuple(0.0, (1 - probability_head_),
                                    (state >= action) ? (state - action) : 0));

  // Head case.
  if (state + action >= state_space_size_ - 1)
    returns.push_back(
        std::make_tuple(1.0, probability_head_, state_space_size_ - 1));
  else
    returns.push_back(std::make_tuple(0.0, probability_head_, state + action));

  return returns;
}

bool Model::IsTerminalState(DP::State state) const {
  // The first and final ones are the final states.
  return (state == 0) || (state == state_space_size_ - 1);
}

const std::vector<DP::Action> Model::FeasibleActions(DP::State state) const {
  assert(!IsTerminalState(state));
  // TODO(xiejw): Can we cache this?
  const int max_state = state_space_size_ - 1;
  const int max_value = std::min(state, max_state - state);
  const int action_count = max_value + 1;

  std::vector<DP::Action> feasible_actions;
  feasible_actions.reserve(action_count);
  for (DP::Action action = 1; action <= max_value; ++action)
    feasible_actions.push_back(action);

  // Cheating: 0 is always a feasiable action according to the gambler problem.
  // Place it at the bottom, so if there is a tie, choose non-zero bet.
  feasible_actions.push_back(0);
  return feasible_actions;
}

}  // namespace GamblerProblem
