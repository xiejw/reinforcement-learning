// Value Iteration Algorithm.
//
// The original Algorithm loops the value evaluation until convergence.
// During each sweep, the new value is updated according to the greedy action
// selection.
//
// As far as the update is not in-place, it is equivalent to
//
// ENTRY:
//   Update the policy by greedily selecting the action with max expected value.
//   Perform one step of Policy evaluation according to the greedy policy.
//   Jump to ENTRY unless convergence.
//
// Final values should be
// Optimal Value Function
//      0     -1     -2     -3
//     -1     -2     -3     -2
//     -2     -3     -2     -1
//     -3     -2     -1      0
// Optimal Policy
//    up  left  left  down
//    up    up    up  down
//    up    up  down  down
//    up right right  down
//
// The result depends on the action search order.
#include <iostream>
#include <memory>

#include "Lib/GamblerProblemModel.h"
#include "Lib/GamblerProblemPolicy.h"
#include "Lib/GamblerProblemPrinter.h"
#include "Lib/PolicyEvaluator.h"
#include "Lib/ValueFunction.h"

constexpr int kMaxValue = 100;
constexpr float kThreshold = 0.005;

int main() {
  const int state_space_size = kMaxValue + 1;
  GamblerProblem::Model model(state_space_size, /*probabiliby_head=*/0.4);
  GamblerProblem::GreedyPolicy policy{model};

  // Must use non-inplace update.
  DP::PolicyEvaluator evaluator{model, /*inPlace=*/false};

  std::unique_ptr<DP::ValueFunction> value_function{
      new DP::ValueFunction{state_space_size}};

  int k = 0;
  while (true) {
    std::cout << "Stage " << k++ << "\n";
    GamblerProblem::PrintValues(*value_function);
    policy.Adapt(*value_function);
    if (evaluator.Update(policy, value_function) < kThreshold) break;
  }

  std::cout << "Optimal Value Function\n";
  GamblerProblem::PrintValues(*value_function);

  std::cout << "Optimal Policy\n";
  GamblerProblem::PrintGreedyPolicy(policy.Actions());
  return 0;
}
