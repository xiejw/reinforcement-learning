#ifndef GRIDWORLDPOLICY
#define GRIDWORLDPOLICY

#include <memory>
#include <utility>
#include <vector>

#include "Lib/Policy.h"

namespace GridWorld {

enum Action : DP::Action { up = 0, down, left, right };

class RandomPolicy : public DP::Policy {
 public:
  std::vector<std::pair<DP::Probability, DP::Action>> Actions(
      DP::State state) const override;
};

}  // namespace GridWorld

#endif
