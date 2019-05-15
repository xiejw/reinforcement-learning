#ifndef GAMBLERPROBLEM_PRINTER
#define GAMBLERPROBLEM_PRINTER

#include <cassert>
#include <iomanip>
#include <iostream>

#include "Lib/Policy.h"
#include "Lib/PolicyEvaluator.h"
#include "Lib/Support/Error.h"

namespace GamblerProblem {

void PrintValues(DP::ValueFunction &value_function) {
  assert(value_function.Size() == 101);
  float *const values = value_function.Values();
  for (DP::State state = 1; state < 100; ++state) {
    std::cout << std::setprecision(3) << std::setw(6) << values[state] << " ";

    if (state % 25 == 0) std::cout << "\n";
  }
  std::cout << "\n";
}

void PrintGreedyPolicy(const DP::Action *const actions) {
  for (DP::State state = 1; state < 100; ++state) {
    std::cout << std::setw(6) << actions[state];
    if (state % 25 == 0) std::cout << "\n";
  }
  std::cout << "\n";
}

}  // namespace GamblerProblem

#endif