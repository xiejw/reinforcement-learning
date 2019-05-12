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

#include "ValueFunction.h"

// The width and height of grid.
constexpr int kGridSize = 4;
constexpr int kNeighborCount = 4;

void PrintValues(ValueFunction &value_function) {
  const float *const values = value_function.Values();
  for (int i = 0; i < kGridSize; ++i) {
    for (int j = 0; j < kGridSize; ++j)
      std::cout << std::setprecision(3) << std::setw(6)
                << values[i * kGridSize + j] << " ";

    std::cout << "\n";
  }
}

inline bool IsTerminalState(int i, int j) {
  return (i == 0 && j == 0) || (i == kGridSize - 1 && j == kGridSize - 1);
}

inline std::unique_ptr<int[]> Neighbors(int i, int j) {
  assert(kNeighborCount == 4);
  std::unique_ptr<int[]> neighbors(new int[kNeighborCount]);
  neighbors[0] = j + kGridSize * (i > 0 ? i - 1 : i);              // Up
  neighbors[1] = j + kGridSize * (i < kGridSize - 1 ? i + 1 : i);  // Down
  neighbors[2] = i * kGridSize + (j > 0 ? j - 1 : j);              // Left
  neighbors[3] = i * kGridSize + (j < kGridSize - 1 ? j + 1 : j);  // Right
  return neighbors;
}

void Update(ValueFunction &value_function, bool inPlace = true) {
  float *const values = value_function.Values();
  std::unique_ptr<float[]> newValues;
  if (!inPlace) newValues.reset(new float[kGridSize * kGridSize]{0});

  for (int i = 0; i < kGridSize; ++i) {
    for (int j = 0; j < kGridSize; ++j) {
      if (IsTerminalState(i, j)) continue;

      const auto &neighbors = Neighbors(i, j);
      float newValue = 0;
      for (int k = 0; k < kNeighborCount; ++k)
        newValue += -1 + values[neighbors[k]];

      if (inPlace)
        values[i * kGridSize + j] = newValue / 4;
      else
        newValues[i * kGridSize + j] = newValue / 4;
    }
  }

  if (!inPlace) value_function.Swap(std::move(newValues));
}

int main() {
  ValueFunction value_function(/*state_space_size=*/kGridSize * kGridSize);
  PrintValues(value_function);

  for (int k = 0; k < 100; ++k) {
    std::cout << "\nStage " << k << ":\n";
    Update(value_function, /*inPlace=*/true);
    PrintValues(value_function);
  }
  return 0;
}
