#ifndef GRIDWORLDPOLICY
#define GRIDWORLDPOLICY

#include <memory>
#include <utility>
#include <vector>

#include "Policy.h"

namespace DP {

enum GridWorldAction : Action { up = 0, down, left, right };

class GridWorldRandomPolicy : public Policy {
 public:
  std::vector<std::pair<Probability, Action>> Actions(
      State state) const override;
};

}  // namespace DP

#endif
