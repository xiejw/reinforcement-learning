import DynamicProgramming
import Foundation

extension GreedyPolicy {
    public func debugString(with context: Context, for model: Model) -> String {
        var output = ""
        let gridSize = context.gridSize
        assert(model.states.count == gridSize * gridSize)

        for i in 0 ..< gridSize {
            for j in 0 ..< gridSize {
                let policyActions = feasibleActions(for: State(index: i * gridSize + j))
                precondition(policyActions.count == 1)
                let action = policyActions[0].action

                switch action {
                case let specialAction as SpecialAction:
                    switch specialAction {
                    case .notAvailable: output.append("   n/a")
                    }
                case let gridWorldAction as GridWorldAction:
                    let actionString = "\(gridWorldAction)"
                    output.append(String(repeating: " ", count: 6 - actionString.count))
                    output.append(actionString)
                default:
                    fatalError("Unexpected action: \(action)")
                }
            }
            output.append("\n")
        }
        return output
    }
}
