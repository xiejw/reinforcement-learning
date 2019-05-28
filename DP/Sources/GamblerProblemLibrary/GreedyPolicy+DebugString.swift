import DynamicProgramming
import Foundation

extension GreedyPolicy {
    public func debugString(
        with context: Context,
        itemCountPerLine: Int = 25
    ) -> String {
        var output = ""

        for i in 1 ... context.maxValue {
            let policyActions = feasibleActions(for: State(index: i))
            precondition(policyActions.count == 1)
            let action = policyActions[0].action

            switch action {
            case let specialAction as SpecialAction:
                switch specialAction {
                case .notAvailable: output.append("   n/a")
                }
            case let gamblerProblemAction as GamblerProblemAction:
                let actionString = "\(gamblerProblemAction.value)"
                output.append(String(repeating: " ", count: 6 - actionString.count))
                output.append(actionString)
            default:
                fatalError("Unexpected action: \(action)")
            }

            if i % itemCountPerLine == 0 {
                output.append("\n")
            }
        }
        return output
    }
}
