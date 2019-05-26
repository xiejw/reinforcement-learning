import DynamicProgramming
import Foundation

extension GreedyPolicy {
    public func debugString(_ context: Context, model: Model) -> String {
        var output = ""
        let gridSize = context.gridSize
        assert(model.states.count == gridSize * gridSize)

        for i in 0 ..< gridSize {
            for j in 0 ..< gridSize {
                let policyActions = feasibleActions(
                    for: GridWorldState(index: i * gridSize + j)
                )
                precondition(policyActions.count == 1)
                let action = policyActions[0].action

                if let specialAction = action as? SpecialAction {
                    switch specialAction {
                    case .notAvailable: output.append("   n/a")
                    }
                } else if let gridWorldAction = action as? GridWorldAction {
                    let actionString = "\(gridWorldAction)"
                    output.append(String(repeating: " ", count: 6 - actionString.count))
                    output.append(actionString)
                } else {
                    fatalError("Unexpected action: \(action)")
                }
            }
            output.append("\n")
        }
        return output
    }
}
