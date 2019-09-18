#ifndef GAMBLERPROBLEM_POLICY
#define GAMBLERPROBLEM_POLICY

#include <utility>
#include <vector>

#include "Lib/DP/Model.h"
#include "Lib/DP/Policy.h"
#include "Lib/DP/ValueFunction.h"

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

}  // namespace GamblerProblem

#endif
