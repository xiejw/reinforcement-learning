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

#include "Lib/DP/PolicyEvaluator.h"
#include "Lib/DP/ValueFunction.h"
#include "Lib/GridWorld/Model.h"
#include "Lib/GridWorld/Policy.h"
#include "Lib/GridWorld/Printer.h"

// The width and height of grid.
constexpr int kGridSize = 4;
constexpr float kThreshold = 0.0001;

int main() {
  std::unique_ptr<DP::ValueFunction> value_function{
      new DP::ValueFunction{/*state_space_size=*/kGridSize * kGridSize}};

  GridWorld::Model model(/*grid_size=*/kGridSize);
  GridWorld::RandomPolicy policy;

  DP::PolicyEvaluator evaluator{model, /*inPlace=*/true};

  GridWorld::PrintValues(*value_function, kGridSize);
  bool stop = false;
  for (int k = 0; !stop; ++k) {
    std::cout << "\nStage " << k << ":\n";
    if (evaluator.Update(policy, value_function) < kThreshold) stop = true;
    GridWorld::PrintValues(*value_function, kGridSize);
  }
  return 0;
}
