#ifndef GRIDWORLD_VALUEFUNCTIONPRINTER
#define GRIDWORLD_VALUEFUNCTIONPRINTER

#include <iomanip>
#include <iostream>

#include "Lib/GridWorldPolicy.h"
#include "Lib/PolicyEvaluator.h"
#include "Lib/Support/Error.h"

namespace GridWorld {

void PrintValues(DP::ValueFunction &value_function, const int grid_size) {
  float *const values = value_function.Values();
  for (int i = 0; i < grid_size; ++i) {
    for (int j = 0; j < grid_size; ++j)
      std::cout << std::setprecision(3) << std::setw(6)
                << values[i * grid_size + j] << " ";

    std::cout << "\n";
  }
}

void PrintGreedyPolicy(const Action *const actions, const int grid_size) {
  for (int i = 0; i < grid_size; ++i) {
    for (int j = 0; j < grid_size; ++j) {
      switch ((int)actions[i * grid_size + j]) {
        case Action::up:
          std::cout << std::setw(6) << "up ";
          break;
        case Action::down:
          std::cout << std::setw(6) << "down ";
          break;
        case Action::left:
          std::cout << std::setw(6) << "left ";
          break;
        case Action::right:
          std::cout << std::setw(6) << "right ";
          break;
        case DP::SpecialAction::na:
          std::cout << std::setw(6) << "n/a ";
          break;
        default:
          eva::FatalError("Unsupported action %d", actions[i * grid_size + j]);
      }
    }

    std::cout << "\n";
  }
}

}  // namespace GridWorld

#endif
