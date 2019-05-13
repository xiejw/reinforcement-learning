#ifndef GRIDWORLD_VALUEFUNCTIONPRINTER
#define GRIDWORLD_VALUEFUNCTIONPRINTER

#include <iomanip>
#include <iostream>

#include "Lib/PolicyEvaluator.h"

namespace GridWorld {

void PrintValues(ValueFunction &value_function, const int grid_size) {
  float *const values = value_function.Values();
  for (int i = 0; i < grid_size; ++i) {
    for (int j = 0; j < grid_size; ++j)
      std::cout << std::setprecision(3) << std::setw(6)
                << values[i * grid_size + j] << " ";

    std::cout << "\n";
  }
}

}  // namespace GridWorld

#endif
