#ifndef GRIDWORLDPOLICY
#define GRIDWORLDPOLICY

#include <memory>
#include <utility>
#include <vector>

#include "Lib/Model.h"
#include "Lib/Policy.h"
#include "Lib/ValueFunction.h"

namespace GridWorld {

enum Action : DP::Action { up = 0, down, left, right };

// A random policy choosing up, down, left, right uniformly.
class RandomPolicy : public DP::Policy {
 public:
  std::vector<std::pair<DP::Probability, DP::Action>> Actions(
      DP::State state) const override;
};

// A auto adapted policy, which greedily chooses the action according to the
// current value function.
//
// Before adapt any value function, a basedline policy, i.e.,g the random
// policy, is used. After invoke `Adapt`, this policy acts greedily.
class GreedyPolicy : public DP::Policy {
 public:
  GreedyPolicy(const DP::Model& model)
      : model_{model}, baseline_policy_{new RandomPolicy} {};

  std::vector<std::pair<DP::Probability, DP::Action>> Actions(
      DP::State state) const override;

  // Returns true if any change is made.
  bool Adapt(DP::ValueFunction& value_function);

  const Action* const Actions() const { return actions_.get(); };

 private:
  const DP::Model& model_;
  std::unique_ptr<DP::Policy> baseline_policy_;
  std::unique_ptr<Action[]> actions_;
};

}  // namespace GridWorld

#endif
