import DynamicProgramming

class GridWorldModel: Model {

    private let context: Context
    private let modelStates: [State]

    public init(context: Context) {
        self.context = context
        var modelStates: [State] = []
        modelStates.reserveCapacity(context.stateCount)
        for i in 0..<context.stateCount {
            modelStates.append(GridWorldState(index: i))
        }
        self.modelStates = modelStates
    }

    func isTerminal(for state: State) -> Bool {
        return state.index == 0 || state.index == context.stateCount - 1
    }

    func transition(from state: State, after action: Action) -> [Transition] {
        assert(state.index >= 0 && state.index < context.stateCount)
        guard let gridWorldAction = action as? GridWorldAction else {
            fatalError("Action must be GridWorldActio.n")
        }

        return [Transition(probability: 1.0, reward: 0.0, newState: state)]

    }

    var states: [State] { return modelStates }
}
