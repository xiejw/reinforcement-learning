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
#include <iomanip>
#include <iostream>
#include <memory>

#include "Lib/GridWorldModel.h"
#include "Lib/GridWorldPolicy.h"
#include "Lib/PolicyEvaluator.h"
#include "Lib/ValueFunction.h"

// The width and height of grid.
constexpr int kGridSize = 4;

void PrintValues(ValueFunction &value_function) {
  float *const values = value_function.Values();
  for (int i = 0; i < kGridSize; ++i) {
    for (int j = 0; j < kGridSize; ++j)
      std::cout << std::setprecision(3) << std::setw(6)
                << values[i * kGridSize + j] << " ";

    std::cout << "\n";
  }
}

int main() {
  auto value_function = std::make_unique<ValueFunction>(
      /*state_space_size=*/kGridSize * kGridSize);
  GridWorld::Model model(kGridSize);
  GridWorld::RandomPolicy policy;

  DP::PolicyEvaluator evaluator{model, /*inPlace=*/true};

  PrintValues(*value_function);

  for (int k = 0; k < 100; ++k) {
    std::cout << "\nStage " << k << ":\n";
    evaluator.Update(policy, value_function);
    PrintValues(*value_function);
  }
  return 0;
}
