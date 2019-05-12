#ifndef POLICY
#define POLICY

#include <memory>
#include <utility>
#include <vector>

namespace DP {

using State = int;
using Probability = float;
using Action = int;

enum GridWorldAction : Action { up = 0, down, left, right };

class Policy {
 public:
  virtual std::vector<std::pair<Probability, Action>> Actions(
      State state) const = 0;
};

class GridWorldRandomPolicy : public Policy {
 public:
  std::vector<std::pair<Probability, Action>> Actions(
      State state) const override;
};

}  // namespace DP

#endif
