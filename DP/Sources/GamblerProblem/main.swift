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
repeat {
    iteration += 1

    print("Iteration \(iteration)")

    _ = policy.Adapt(from: valueFunction)
    print("New policy:")
    print(policy.debugString(with: context))

    maxDelta = evaluator.Evaluation(valueFunction, using: policy)
    print("maxDelta \(maxDelta)")
} while maxDelta >= 0.0001
