import DynamicProgramming
import Foundation
import GridWorld

let context = Context(stateCount: 16)
let model = GridWorldModel(context: context)
let policy = GridWorldRandomPolicy()

let valueFunction = ValueFunction(stateCount: context.stateCount)
let evaluator = PolicyEvaluator(model: model, inPlaceUpdate: true)

// Iterate until ValueFunction is converged.
var maxDelta: FloatType
var iteration = 0
repeat {
    iteration += 1
    maxDelta = evaluator.Evaluation(valueFunction, using: policy)

    print("Iteration \(iteration): maxDelta \(maxDelta)")
    print(valueFunction.debugString(with: context))
} while maxDelta > 0.0001
