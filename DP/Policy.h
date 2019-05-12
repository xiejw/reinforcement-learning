#ifndef POLICY
#define POLICY

#include <memory>
#include <utility>
#include <vector>

namespace DP {

using State = int;
using Probability = float;

enum Action { up, down, left, right };

class Policy {
  virtual std::vector<std::pair<Probability, Action>> Actions(
      State state) const;
};

class RandomPolicy : Policy {
  std::vector<std::pair<Probability, Action>> Actions(
      State state) const override;
};

}  // namespace DP

#endif
