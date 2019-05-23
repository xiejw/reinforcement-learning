/// Evaluates
public class PolicyEvaluator {
    private let model: Model
    private let inPlaceUpdate: Bool

    public init(model: Model, inPlaceUpdate: Bool = true) {
        self.model = model
        self.inPlaceUpdate = inPlaceUpdate
    }

    func Update(_ valueFunction: ValueFunction, using policy: Policy) -> FloatType {
        let stateCount = valueFunction.count
        var maxDelta: FloatType = 0

        for stateIndex in 0..<stateCount {
            if model.isTerminal(for: stateIndex) {
                continue
            }

            var newValue: FloatType = 0
            for (actionProbabiliy, action) in policy.feasibleActions(for: stateIndex) {
                for transition in model.transition(from: stateIndex, after: action) {
                    newValue += actionProbabiliy * transition.probability * (
                        transition.reward + valueFunction[transition.newState])
                }
            }

            maxDelta = max(maxDelta, abs(newValue - valueFunction[stateIndex]))
        }
        return maxDelta
    }
}
