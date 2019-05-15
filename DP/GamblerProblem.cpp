// Gambler Problem with Value Iteration Algorithm.
//
// The result depends on the action search order. In particular, for any greed
// policy selection, if the value function is converged already, then action 0
// (stake 0, i.e., no bet) is always one of the best actions. So, we should
// consider 0 as the last action by placing it in the end of action search
// order.
//
// Check GamblerProblemModel file and look for FeasiableActions for details.
//
// In addition, for numerical program, it is up to the precision whether action
// 0 will be the best. So, using double is important. For probabiliby_head =
// 0.75, the system might favor non-zero action due to super tiny accuracy issue
// during the convergence process.
#include <iostream>
#include <memory>

#include "Lib/GamblerProblemModel.h"
#include "Lib/GamblerProblemPolicy.h"
#include "Lib/GamblerProblemPrinter.h"
#include "Lib/PolicyEvaluator.h"
#include "Lib/ValueFunction.h"

constexpr int kMaxValue = 100;
constexpr double kThreshold = 0.0001;

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
  GamblerProblem::PrintGreedyPolicy(policy.Actions(),
                                    /*max_state_to_print=*/kMaxValue - 1);
  return 0;
}
