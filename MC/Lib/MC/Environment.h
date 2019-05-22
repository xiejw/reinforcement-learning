#ifndef MODEL
#define MODEL

#include <memory>
#include <tuple>
#include <vector>

namespace MC {

using Reward = double;

class Envinronment {
 public:
  virtual std::tuple<Reward, bool, std::unique_ptr<State>> Next(
      State state, Action action) const = 0;

  virtual int StateSpaseSizt() const = 0;

  virtual const std::vector<Action> FeasibleActions(State state) const = 0;

  virtual bool IsTerminalState(State state) const = 0;
};

}  // namespace MC

#endif
