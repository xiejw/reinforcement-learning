#ifndef DP_MODEL
#define DP_MODEL

#include <memory>
#include <tuple>
#include <vector>

#include "Lib/DP/Policy.h"

namespace DP {

using Reward = double;

class Model {
 public:
  virtual std::vector<std::tuple<Reward, Probability, State>> Transition(
      State state, Action action) const = 0;

  virtual int StateSpaseSizt() const = 0;

  virtual const std::vector<Action> FeasibleActions(State state) const = 0;

  virtual bool IsTerminalState(State state) const = 0;
};

}  // namespace DP

#endif
