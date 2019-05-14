#include "Lib/GridWorldModel.h"

#include "Lib/GridWorldPolicy.h"
#include "Lib/Support/Error.h"

namespace GridWorld {

std::vector<std::tuple<DP::Reward, DP::Probability, DP::State>>
Model::Transition(DP::State state, DP::Action action) const {
  std::vector<std::tuple<DP::Reward, DP::Probability, DP::State>> returns;
  int x = state / grid_size_, y = state % grid_size_;

  switch (action) {
    case Action::up:
      if (x > 0) x -= 1;
      break;
    case Action::down:
      if (x < grid_size_ - 1) x += 1;
      break;
    case Action::left:
      if (y > 0) y -= 1;
      break;
    case Action::right:
      if (y < grid_size_ - 1) y += 1;
      break;
    default:
      eva::FatalError("Unsupported action %d", action);
  }
  returns.push_back(std::make_tuple(-1.0, 1.0, x * grid_size_ + y));
  return returns;
}

bool Model::IsTerminalState(DP::State state) const {
  return (state == 0) || (state == grid_size_ * grid_size_ - 1);
}

}  // namespace GridWorld
