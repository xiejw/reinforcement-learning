import DynamicProgramming
import GridWorld

let context = Context(stateCount: 16)
let model = GridWorldModel(context: context)
let evaluator = PolicyEvaluator(model: model, inPlaceUpdate: true)

let policy = GreedyPolicy(model: model)

// Outer loop: Iterate until policy is stable.
var iteration = 0
while true {
    iteration += 1

    // Use new ValueFunction for each iteration.
    let valueFunction = ValueFunction(stateCount: context.stateCount)

    // Inner loop: Iterate until ValueFunction is converged.
    var innerLoopIteration = 0, maxDelta: FloatType
    repeat {
        innerLoopIteration += 1
        maxDelta = evaluator.Evaluation(valueFunction, using: policy)
        if innerLoopIteration > 500 {
            print("Inner Loop reaches max 500 iterations.")
            break
        }
    } while maxDelta > 0.0001

    print("Iteration \(iteration): maxDelta \(maxDelta)")
    print(valueFunction.debugString(context))

    if !policy.Adapt(from: valueFunction) {
        print("Policy iteration converged.")
        print(policy.debugString(context, model: model))
        break
    }
}
