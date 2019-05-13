#include <cassert>

#include "Lib/PolicyEvaluator.h"

namespace DP {

namespace {

void UpdateValue(const DP::Model &model, const DP::Policy &policy,
                 ValueFunction &old_value_function,
                 ValueFunction &new_value_function) {
  const int state_space_size = old_value_function.Size();
  assert(state_space_size == new_value_function.Size());

  float *const old_values = old_value_function.Values();
  float *const new_values = new_value_function.Values();

  for (DP::State state = 0; state < state_space_size; ++state) {
    if (model.IsTerminalState(state)) {
      new_values[state] = old_values[state];
      continue;
    }

    float new_value = 0;
    for (auto &actionChoice : policy.Actions(state)) {
      auto &action_probability = actionChoice.first;
      auto &action = actionChoice.second;

      for (auto &transition : model.Transition(state, action)) {
        auto &reward = std::get<0>(transition);
        auto &state_probability = std::get<1>(transition);
        auto &new_state = std::get<2>(transition);

        new_value += action_probability * state_probability *
                     (reward + old_values[new_state]);
      }
    }

    new_values[state] = new_value;
  }
}

}  // namespace

void PolicyEvaluator::Update(
    const DP::Policy &policy,
    std::unique_ptr<ValueFunction> &value_function) const {
  if (in_place_) {
    UpdateValue(model_, policy, *value_function, *value_function);
    return;
  }

  // Creates a new buffer.
  const int state_space_size = value_function->Size();
  std::unique_ptr<ValueFunction> new_value_function{
      new ValueFunction{state_space_size}};
  UpdateValue(model_, policy, *value_function, *new_value_function);
  value_function.swap(new_value_function);
}

}  // namespace DP
