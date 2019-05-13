#ifndef GRIDWORLDMODEL
#define GRIDWORLDMODEL

#include <memory>
#include <tuple>
#include <vector>

#include "Lib/Model.h"
#include "Lib/Policy.h"

namespace GridWorld {

class Model : public DP::Model {
 public:
  Model(int grid_size) : grid_size_{grid_size} {};

  std::vector<std::tuple<DP::Reward, DP::Probability, DP::State>> Transition(
      DP::State state, DP::Action action) const override;

  bool IsTerminalState(DP::State state) const override;

 private:
  int grid_size_;
};

}  // namespace GridWorld

#endif
