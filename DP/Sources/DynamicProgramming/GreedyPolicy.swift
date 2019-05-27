public class GreedyPolicy: Policy {
    private let model: Model
    private var initialized = false

    public init(model: Model) {
        self.model = model
    }

    private lazy var actions: [Action] = {
        let allStates = model.states
        var arbitraryActions: [Action] = Array(
            repeating: SpecialAction.notAvailable,
            count: allStates.count
        )

        for state in allStates {
            guard !model.isTerminal(for: state) else {
                continue
            }

            let modelFeasibleActions = model.feasibleActions(for: state)
            precondition(modelFeasibleActions.count > 0)
            arbitraryActions[state.index] = modelFeasibleActions[0]
        }
        return arbitraryActions
    }()

    public func feasibleActions(for state: State) -> [(probability: FloatType, action: Action)] {
        assert(state.index >= 0 && state.index < actions.count)
        return [(probability: 1.0, actions[state.index])]
    }

    public func Adapt(from valueFunction: ValueFunction) -> Bool {
        let allStates = model.states
        let oldActionsCopy = actions
        assert(oldActionsCopy.count == allStates.count)

        actions = Array(repeating: SpecialAction.notAvailable, count: allStates.count)

        var changed = false
        for state in allStates {
            guard !model.isTerminal(for: state) else {
                // Terminal state's action does not count to the `changed` logic.
                continue
            }

            var maxValue: FloatType?
            for action in model.feasibleActions(for: state) {
                var newValue: FloatType = 0
                for transition in model.transition(from: state, after: action) {
                    newValue += transition.probability * (
                        transition.reward + valueFunction[transition.newState])
                }

                if maxValue == nil || newValue > maxValue! {
                    maxValue = newValue
                    actions[state.index] = action
                }
            }
            if actions[state.index].value != oldActionsCopy[state.index].value {
                changed = true
            }
        }

        return changed
    }
}
