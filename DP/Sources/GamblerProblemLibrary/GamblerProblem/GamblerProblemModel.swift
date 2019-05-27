import DynamicProgramming

/// The model for the GamblerProblem.
public class GamblerProblemModel: Model {
    private let context: Context

    public init(context: Context) {
        self.context = context
    }

    public func isTerminal(for state: State) -> Bool {
        return state.index == 0 || state.index == context.stateCount - 1
    }

    private lazy var modelStates: [State] = {
        var modelStates: [State] = []
        modelStates.reserveCapacity(context.stateCount)
        for i in 0 ..< context.stateCount {
            modelStates.append(State(index: i))
        }
        return modelStates
    }()

    public var states: [State] { return modelStates }
}

extension GamblerProblemModel {
    public func feasibleActions(for state: State) -> [Action] {
        assert(!isTerminal(for: state))
        return []
    }

    public func transition(from _: State, after _: Action) -> [Transition] {
        return []
    }
}
