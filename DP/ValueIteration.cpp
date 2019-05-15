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
//   n/a  left  left  down
//    up    up    up  down
//    up    up  down  down
//    up right right   n/a
//
// The result depends on the action search order.
#include <iostream>
#include <memory>

#include "Lib/GreedyPolicy.h"
#include "Lib/GridWorldModel.h"
#include "Lib/GridWorldPolicy.h"
#include "Lib/GridWorldPrinter.h"
#include "Lib/PolicyEvaluator.h"
#include "Lib/ValueFunction.h"

// The width and height of grid.
constexpr int kGridSize = 4;
constexpr double kThreshold = 0.0001;

int main() {
  GridWorld::Model model(/*grid_size=*/kGridSize);
  DP::GreedyPolicy policy{
      model, std::unique_ptr<DP::Policy>{new GridWorld::RandomPolicy}};

  // Must use non-inplace update.
  DP::PolicyEvaluator evaluator{model, /*inPlace=*/false};

  // Generate random value function. But
  // - keeps terminal states having the correct value.
  // - makes the non-terminal states have very wrong value *=10 to see whether
  //   the algorithm can fix it.
  int state_space_size = kGridSize * kGridSize;
  std::unique_ptr<DP::ValueFunction> value_function{
      new DP::ValueFunction{state_space_size, /*random=*/true}};
  for (DP::State s = 0; s < state_space_size; ++s)
    if (model.IsTerminalState(s))
      value_function->Values()[s] = 0.0;
    else
      value_function->Values()[s] *= 10;

  int k = 0;
  while (true) {
    std::cout << "Stage " << k++ << "\n";
    GridWorld::PrintValues(*value_function, kGridSize);
    policy.Adapt(*value_function);
    if (evaluator.Update(policy, value_function) < kThreshold) break;
  }

  std::cout << "Optimal Value Function\n";
  GridWorld::PrintValues(*value_function, kGridSize);

  std::cout << "Optimal Policy\n";
  GridWorld::PrintGreedyPolicy(policy.Actions(), kGridSize);
  return 0;
}
