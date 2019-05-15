// Value Iteration Algorithm.
//
// Check GamblerProblemModel file and look for FeasiableActions.
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
constexpr float kThreshold = 0.0001;

int main() {
  const int state_space_size = kMaxValue + 1;
  GamblerProblem::Model model(state_space_size, /*probabiliby_head=*/0.25);
  GamblerProblem::GreedyPolicy policy{model};

  // Must use non-inplace update.
  DP::PolicyEvaluator evaluator{model, /*inPlace=*/false};

  std::unique_ptr<DP::ValueFunction> value_function{
      new DP::ValueFunction{state_space_size}};

  int k = 0;
  bool stop = false;
  while (!stop) {
    std::cout << "Stage " << k++ << "\n";
    GamblerProblem::PrintValues(*value_function);
    policy.Adapt(*value_function);
    if (evaluator.Update(policy, value_function) < kThreshold) stop = true;
  }

  std::cout << "Optimal Value Function\n";
  GamblerProblem::PrintValues(*value_function);

  std::cout << "Optimal Policy\n";
  GamblerProblem::PrintGreedyPolicy(policy.Actions());
  return 0;
}
