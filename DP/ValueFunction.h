#ifndef VALUE_FUNCTION
#define VALUE_FUNCTION

#include <memory>

class ValueFunction {
 public:
  ValueFunction(int state_space_size) : state_space_size_{state_space_size} {
    values_.reset(new float[state_space_size]{0});
  }

  float *const Values() { return values_.get(); }

  void Swap(std::unique_ptr<float[]> new_values) { values_.swap(new_values); }

  int Size() { return state_space_size_; }

 private:
  int state_space_size_;
  std::unique_ptr<float[]> values_;
};

#endif
