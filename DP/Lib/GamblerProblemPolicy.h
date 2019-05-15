#ifndef GAMBLERPROBLEM_OLICY
#define GAMBLERPROBLEM_OLICY

#include <memory>
#include <utility>
#include <vector>

#include "Lib/Model.h"
#include "Lib/Policy.h"
#include "Lib/ValueFunction.h"

namespace GamblerProblem {

// A random policy choosing any value for stakes randomly.
class RandomPolicy : public DP::Policy {
 public:
  RandomPolicy(const DP::Model& model) : model_{model} {};

  std::vector<std::pair<DP::Probability, DP::Action>> Actions(
      DP::State state) const override;

 private:
  const DP::Model& model_;
};

// A auto adapted policy, which greedily chooses the action according to the
// current value function.
//
// Before adapt any value function, a basedline policy, i.e.,g the random
// policy, is used. After invoke `Adapt`, this policy acts greedily.
class GreedyPolicy : public DP::Policy {
 public:
  GreedyPolicy(const DP::Model& model)
      : model_{model}, baseline_policy_{new RandomPolicy{model}} {};

  std::vector<std::pair<DP::Probability, DP::Action>> Actions(
      DP::State state) const override;

  // Returns true if any change is made.
  bool Adapt(DP::ValueFunction& value_function);

  const DP::Action* const Actions() const { return actions_.get(); };

 private:
  const DP::Model& model_;
  std::unique_ptr<DP::Policy> baseline_policy_;
  std::unique_ptr<DP::Action[]> actions_;
};

}  // namespace GamblerProblem

#endif
