#ifndef VALUE_FUNCTION
#define VALUE_FUNCTION

#include <memory>

namespace DP {

class ValueFunction {
 public:
  ValueFunction(int state_space_size) : state_space_size_{state_space_size} {
    values_.reset(new float[state_space_size]{0});
  }

  float *const Values() { return values_.get(); }

  int Size() { return state_space_size_; }

 private:
  int state_space_size_;
  std::unique_ptr<float[]> values_;
};

}  // namespace DP

#endif
