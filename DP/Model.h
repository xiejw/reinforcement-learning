#ifndef MODEL
#define MODEL

#include <memory>
#include <tuple>
#include <vector>

#include "Policy.h"

namespace DP {

using Reward = float;

class Model {
 public:
  virtual std::vector<std::tuple<Reward, Probability, State>> Transition(
      State state, Action action) const = 0;

  virtual bool IsTerminalState(State state) const = 0;
};

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
