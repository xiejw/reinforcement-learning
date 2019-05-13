// Given a policy, e.g., random policy in this case, evaluate the value
// function.
//
// Final values should be
//     0    -14    -20    -22
//   -14    -18    -20    -20
//   -20    -20    -18    -14
//   -22    -20    -14      0
//
// `inPlace==true` converges faster.
#include <memory>

#include "Lib/GridWorldModel.h"
#include "Lib/GridWorldPolicy.h"
#include "Lib/GridWorldValueFunctionPrinter.h"
#include "Lib/PolicyEvaluator.h"
#include "Lib/ValueFunction.h"

// The width and height of grid.
constexpr int kGridSize = 4;

int main() {
  std::unique_ptr<DP::ValueFunction> value_function{
      new DP::ValueFunction{/*state_space_size=*/kGridSize * kGridSize}};

  GridWorld::Model model(/*grid_size=*/kGridSize);
  GridWorld::RandomPolicy policy;

  DP::PolicyEvaluator evaluator{model, /*inPlace=*/false};

  GridWorld::PrintValues(*value_function, kGridSize);
  bool stop = false;
  for (int k = 0; !stop; ++k) {
    std::cout << "\nStage " << k << ":\n";
    if (evaluator.Update(policy, value_function) < 0.005) stop = true;
    GridWorld::PrintValues(*value_function, kGridSize);
  }
  return 0;
}
