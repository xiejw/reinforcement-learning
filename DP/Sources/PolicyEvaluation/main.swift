import DynamicProgramming
import Foundation
import GridWorld

let context = Context(stateCount: 16)
let model = GridWorldModel(context: context)
let policy = GridWorldRandomPolicy()

let valueFunction = ValueFunction(stateCount: context.stateCount)
let evaluator = PolicyEvaluator(model: model)

var k = 0
while true {
    let maxDelta = evaluator.Update(valueFunction, using: policy)
    k += 1

    print("Stage \(k): maxDetal \(maxDelta)")
    valueFunction.PrintDebugString(context: context)
    print("")

    if maxDelta < 0.0001 {
        break
    }
}

print("hello policy")
