#ifndef DP_GREEDYPOLICY
#define DP_GREEDYPOLICY

#include <memory>
#include <utility>
#include <vector>

#include "Lib/DP/Model.h"
#include "Lib/DP/Policy.h"
#include "Lib/DP/ValueFunction.h"

namespace DP {

// A auto adapted policy, which greedily chooses the action according to the
// current value function.
//
// Before adapt any value function, a basedline policy, i.e.,g the random
// policy, is used. After invoke `Adapt`, this policy acts greedily.
class GreedyPolicy : public Policy {
 public:
  GreedyPolicy(const DP::Model& model, std::unique_ptr<Policy> baseline_policy)
      : model_{model}, baseline_policy_{std::move(baseline_policy)} {};

  std::vector<std::pair<DP::Probability, DP::Action>> Actions(
      DP::State state) const override;

  // Returns true if any change is made.
  bool Adapt(ValueFunction& value_function);

  const Action* const Actions() const { return actions_.get(); };

 private:
  const DP::Model& model_;
  std::unique_ptr<Policy> baseline_policy_;
  std::unique_ptr<Action[]> actions_;
};

}  // namespace DP

#endif
