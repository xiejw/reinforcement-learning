// Policy Iteration Algorithm.
//
// Final values should be
//   up  left  left  down
//   up    up    up  down
//   up    up  down  down
//   up right right  down
//
// The result depends on the action search direction.
#include <iostream>
#include <memory>

#include "Lib/GridWorldModel.h"
#include "Lib/GridWorldPolicy.h"
#include "Lib/GridWorldValueFunctionPrinter.h"
#include "Lib/PolicyEvaluator.h"
#include "Lib/ValueFunction.h"

// The width and height of grid.
constexpr int kGridSize = 4;
constexpr float kThreshold = 0.005;

int main() {
  GridWorld::Model model(/*grid_size=*/kGridSize);
  GridWorld::GreedyPolicy policy{model};

  DP::PolicyEvaluator evaluator{model, /*inPlace=*/false};

  // The outer loop to detect whether optimial greedy policy is stable or not.
  bool stop = false;
  while (!stop) {
    std::cout << "Policy Evaluation\n";
    std::unique_ptr<DP::ValueFunction> value_function{
        new DP::ValueFunction{/*state_space_size=*/kGridSize * kGridSize}};

    // The inner loop to perform Policy evaluation.
    while (evaluator.Update(policy, value_function) >= kThreshold)
      ;

    GridWorld::PrintValues(*value_function, kGridSize);

    // Make the policy greedy w.r.t. current value function.
    if (!policy.Adapt(*value_function)) stop = true;

    std::cout << "New Policy\n";
    GridWorld::PrintGreedyPolicy(policy.Actions(), kGridSize);
  }
  return 0;
}
