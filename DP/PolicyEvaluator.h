#ifndef POLICYEVALUATOR
#define POLICYEVALUATOR

#include <memory>
#include <utility>
#include <vector>

namespace DP {

class Policy {
 public:
  virtual std::vector<std::pair<Probability, Action>> Actions(
      State state) const = 0;
};

}  // namespace DP

#endif
