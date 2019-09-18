#ifndef DP_POLICYEVALUATOR
#define DP_POLICYEVALUATOR

#include <memory>
#include <utility>
#include <vector>

#include "Lib/DP/Model.h"
#include "Lib/DP/Policy.h"
#include "Lib/DP/ValueFunction.h"

namespace DP {

class PolicyEvaluator {
 public:
  PolicyEvaluator(const Model &model, bool in_place = true)
      : model_{model}, in_place_{in_place} {};

  double Update(const Policy &policy,
                std::unique_ptr<ValueFunction> &value_function) const;

 private:
  const Model &model_;
  bool in_place_;
};

}  // namespace DP

#endif
