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

// The width and height of grid.
constexpr int kGridSize = 4;
constexpr int kNeighborCount = 4;

void PrintValues(std::unique_ptr<float[]> &values) {
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

void Update(std::unique_ptr<float[]> &values, bool inPlace = true) {
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

  if (!inPlace) values.swap(newValues);
}

int main() {
  std::unique_ptr<float[]> values{new float[kGridSize * kGridSize]{0}};
  PrintValues(values);

  for (int k = 0; k < 100; ++k) {
    std::cout << "\nStage " << k << ":\n";
    Update(values, /*inPlace=*/true);
    PrintValues(values);
  }
  return 0;
}
