/// Evaluates the state values for the model.
public class PolicyEvaluator {
    private let model: Model
    private let inPlaceUpdate: Bool

    public init(model: Model, inPlaceUpdate: Bool = true) {
        self.model = model
        self.inPlaceUpdate = inPlaceUpdate
    }

    func Update(_ valueFunction: ValueFunction, using policy: Policy) -> FloatType {
        var maxDelta: FloatType = 0

        for state in model.states {
            if model.isTerminal(for: state) {
                continue
            }

            var newValue: FloatType = 0
            for (actionProbabiliy, action) in policy.feasibleActions(for: state) {
                for transition in model.transition(from: state, after: action) {
                    newValue += actionProbabiliy * transition.probability * (
                        transition.reward + valueFunction[transition.newState])
                }
            }

            maxDelta = max(maxDelta, abs(newValue - valueFunction[state]))
        }
        return maxDelta
    }
}
