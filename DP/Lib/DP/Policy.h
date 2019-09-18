#ifndef DP_POLICY
#define DP_POLICY

#include <memory>
#include <utility>
#include <vector>

namespace DP {

using State = int;
using Probability = double;

// All valid actions must be non-negnitive.
using Action = int;

enum SpecialAction : Action { na = -1 };

class Policy {
 public:
  virtual std::vector<std::pair<Probability, Action>> Actions(
      State state) const = 0;
  virtual ~Policy(){};
};

}  // namespace DP

#endif
