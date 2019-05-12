#include "Support/Error.h"

#include "GridWorldModel.h"
#include "GridWorldPolicy.h"

namespace DP {

std::vector<std::tuple<Reward, Probability, State>> GridWorldModel::Transition(
    State state, Action action) const {
  std::vector<std::tuple<Reward, Probability, State>> returns;
  int x = state / grid_size_, y = state % grid_size_;

  switch (action) {
    case GridWorldAction::up:
      if (x > 0) x -= 1;
      break;
    case GridWorldAction::down:
      if (x < grid_size_ - 1) x += 1;
      break;
    case GridWorldAction::left:
      if (y > 0) y -= 1;
      break;
    case GridWorldAction::right:
      if (y < grid_size_ - 1) y += 1;
      break;
    default:
      eva::FatalError("Unsupported action %d", action);
  }
  returns.push_back(std::make_tuple(-1.0, 1.0, x * grid_size_ + y));
  return returns;
}

bool GridWorldModel::IsTerminalState(State state) const {
  return (state == 0) || (state == grid_size_ * grid_size_ - 1);
}

}  // namespace DP
