#ifndef MODEL
#define MODEL

#include <memory>
#include <tuple>
#include <vector>

#include "Lib/Policy.h"

namespace DP {

using Reward = float;

class Model {
 public:
  virtual std::vector<std::tuple<Reward, Probability, State>> Transition(
      State state, Action action) const = 0;

  virtual bool IsTerminalState(State state) const = 0;
};

}  // namespace DP

#endif
