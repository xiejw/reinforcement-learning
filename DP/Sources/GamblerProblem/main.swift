// Gambler Problem.
import DynamicProgramming
import GamblerProblemLibrary

let context = Context(stateCount: 100 + 1)
let model = GamblerProblemModel(context: context, probabilityOfHead: 0.25)
let evaluator = PolicyEvaluator(model: model, inPlaceUpdate: false)

let policy = GreedyPolicy(model: model)
let valueFunction = ValueFunction(stateCount: context.stateCount)

// Outer loop: Iterate until policy is stable.
var iteration = 0, maxDelta: FloatType
while true {
    iteration += 1

    print("Iteration \(iteration)")
    // print(valueFunction.debugString(with: context))

    _ = policy.Adapt(from: valueFunction)
    print("New policy:")
    // print(policy.debugString(with: context, for: model))

    maxDelta = evaluator.Evaluation(valueFunction, using: policy)
    if maxDelta < 0.0001 {
        print("ValueFunction converged.")
        break
    }

    print("maxDelta \(maxDelta)")
}
