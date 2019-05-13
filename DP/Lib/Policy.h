#ifndef POLICY
#define POLICY

#include <memory>
#include <utility>
#include <vector>

namespace DP {

using State = int;
using Probability = float;
using Action = int;

class Policy {
 public:
  virtual std::vector<std::pair<Probability, Action>> Actions(
      State state) const = 0;
};

}  // namespace DP

#endif
