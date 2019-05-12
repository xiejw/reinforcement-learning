#ifndef GRIDWORLDMODEL
#define GRIDWORLDMODEL

#include <memory>
#include <tuple>
#include <vector>

#include "Model.h"
#include "Policy.h"

namespace DP {

class GridWorldModel : public Model {
 public:
  GridWorldModel(int grid_size) : grid_size_{grid_size} {};

  std::vector<std::tuple<Reward, Probability, State>> Transition(
      State state, Action action) const override;

  bool IsTerminalState(State state) const override;

 private:
  int grid_size_;
};

}  // namespace DP

#endif
