#ifndef VALUE_FUNCTION
#define VALUE_FUNCTION

#include <chrono>
#include <memory>
#include <random>

namespace DP {

class ValueFunction {
 public:
  ValueFunction(int state_space_size, bool random = false)
      : state_space_size_{state_space_size} {
    if (!random) {
      values_.reset(new double[state_space_size]{0});
    } else {
      values_.reset(new double[state_space_size]);
      std::default_random_engine rng;
      rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
      std::uniform_int_distribution<int> distribution(0, 10);

      for (int i = 0; i < state_space_size; ++i) {
        values_[i] = distribution(rng) * 1.0 / 10;
      }
    }
  }

  double *const Values() { return values_.get(); }

  int Size() { return state_space_size_; }

 private:
  int state_space_size_;
  std::unique_ptr<double[]> values_;
};

}  // namespace DP

#endif
