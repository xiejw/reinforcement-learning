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
#include <cassert>
#include <iomanip>
#include <iostream>
#include <memory>

#include "Model.h"
#include "Policy.h"
#include "ValueFunction.h"

// The width and height of grid.
constexpr int kGridSize = 4;

void PrintValues(ValueFunction &value_function) {
  const float *const values = value_function.Values();
  for (int i = 0; i < kGridSize; ++i) {
    for (int j = 0; j < kGridSize; ++j)
      std::cout << std::setprecision(3) << std::setw(6)
                << values[i * kGridSize + j] << " ";

    std::cout << "\n";
  }
}

void Update(const DP::Model &model, const DP::Policy &policy,
            ValueFunction &value_function, bool inPlace = true) {
  const int state_space_size = value_function.Size();
  float *const values = value_function.Values();
  std::unique_ptr<float[]> newValues;
  // FIXME: New VAlues.
  if (!inPlace) newValues.reset(new float[state_space_size]{0});

  for (DP::State state = 0; state < state_space_size; ++state) {
    if (model.IsTerminalState(state)) continue;

    float new_value = 0;
    for (auto &actionChoice : policy.Actions(state)) {
      auto &action_probability = actionChoice.first;
      auto &action = actionChoice.second;

      for (auto &transition : model.Transition(state, action)) {
        auto &reward = std::get<0>(transition);
        auto &state_probability = std::get<1>(transition);
        auto &new_state = std::get<2>(transition);

        new_value += action_probability * state_probability *
                     (reward + values[new_state]);
      }
    }

    if (inPlace)
      values[state] = new_value;
    else
      newValues[state] = new_value;
  }

  if (!inPlace) value_function.Swap(std::move(newValues));
}

int main() {
  ValueFunction value_function(/*state_space_size=*/kGridSize * kGridSize);
  DP::GridWorldModel model(kGridSize);
  DP::GridWorldRandomPolicy policy;

  PrintValues(value_function);

  for (int k = 0; k < 100; ++k) {
    std::cout << "\nStage " << k << ":\n";
    Update(model, policy, value_function, /*inPlace=*/true);
    PrintValues(value_function);
  }
  return 0;
}
