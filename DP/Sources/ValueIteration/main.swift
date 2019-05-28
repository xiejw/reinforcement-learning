// Value Iteration Algorithm.
//
// The original Algorithm loops the value evaluation until convergence.
// During each sweep, the new value is updated according to the greedy action
// selection.
//
// As far as the update is not in-place, it is equivalent to
//
// ENTRY:
//   Update the policy by greedily selecting the action with max expected value.
//   Perform one step of Policy evaluation according to the greedy policy.
//   Jump to ENTRY unless convergence.
import DynamicProgramming
import GridWorld

let context = Context(stateCount: 16)
let model = GridWorldModel(context: context)
let evaluator = PolicyEvaluator(model: model, inPlaceUpdate: false)

let policy = GreedyPolicy(model: model)
let valueFunction = ValueFunction(stateCount: context.stateCount)

// Outer loop: Iterate until value function is stable.
var iteration = 0, maxDelta: FloatType
repeat {
    iteration += 1

    print("Iteration \(iteration)")
    print(valueFunction.debugString(with: context))

    _ = policy.Adapt(from: valueFunction)
    print("New policy:\n\(policy.debugString(with: context, for: model))")

    maxDelta = evaluator.Evaluation(valueFunction, using: policy)
    print("maxDelta \(maxDelta)")

} while maxDelta >= 0.0001

print("ValueFunction converged.")
