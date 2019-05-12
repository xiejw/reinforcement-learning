// Given a policy, e.g., random policy in this case, evaluate the value
// function.
#include <iomanip>
#include <iostream>
#include <memory>

// The width and height of grid.
constexpr int kGridSize = 4;
constexpr int kNeighborCount = 4;

void Print(float *values) {
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
  Print(values.get());
  for (int k = 0; k < 10; ++k) {
    std::cout << "\nStage " << k << ":\n";
    Update(values, /*inPlace=*/true);
    Print(values.get());
  }
  return 0;
}
