#ifndef GAMBLERPROBLEM_MODEL
#define GAMBLERPROBLEM_MODEL

#include <chrono>
#include <memory>
#include <random>
#include <tuple>
#include <vector>

#include "Lib/Model.h"
#include "Lib/Policy.h"

namespace GamblerProblem {

class Model : public DP::Model {
 public:
  // seed = 0 means we use clock time.
  Model(int state_space_size, float probability_head, int seed = 0)
      : state_space_size_{state_space_size},
        probability_head_{probability_head},
        rng_{},
        distribution_{1, 10} {
    rng_.seed(
        seed != 0
            ? seed
            : std::chrono::system_clock::now().time_since_epoch().count());
  };

  std::vector<std::tuple<DP::Reward, DP::Probability, DP::State>> Transition(
      DP::State state, DP::Action action) const override;

  int StateSpaseSizt() const override { return state_space_size_; }

  const std::vector<DP::Action> FeasibleActions(DP::State state) const override;

  bool IsTerminalState(DP::State state) const override;

 private:
  int state_space_size_;
  float probability_head_;

  std::default_random_engine rng_;
  std::uniform_int_distribution<int> distribution_;
};

}  // namespace GamblerProblem

#endif
