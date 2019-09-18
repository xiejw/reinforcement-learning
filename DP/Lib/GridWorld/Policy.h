#ifndef GRIDWORLD_POLICY
#define GRIDWORLD_POLICY

#include <utility>
#include <vector>

#include "Lib/DP/Policy.h"

namespace GridWorld {

enum Action : DP::Action { up = 0, down, left, right };

// A random policy choosing up, down, left, right uniformly.
class RandomPolicy : public DP::Policy {
 public:
  std::vector<std::pair<DP::Probability, DP::Action>> Actions(
      DP::State state) const override;
};

}  // namespace GridWorld

#endif
