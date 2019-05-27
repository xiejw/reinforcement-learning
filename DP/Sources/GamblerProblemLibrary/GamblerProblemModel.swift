import DynamicProgramming

/// The model for the GamblerProblem.
public class GamblerProblemModel: Model {
    private let context: Context
    private let probabilityOfHead: FloatType

    public init(context: Context, probabilityOfHead: FloatType) {
        self.context = context
        self.probabilityOfHead = probabilityOfHead
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
        let maxValueToBet = min(state.index, context.maxValue - state.index)

        var actions: [Action] = []
        actions.reserveCapacity(maxValueToBet + 1)

        for i in 1 ... maxValueToBet {
            actions.append(GamblerProblemAction(value: i))
        }
        // Cheating: 0 is always a feasiable action according to the gambler problem.  Place it at
        // the bottom, so if there is a tie, choose non-zero bet.
        actions.append(GamblerProblemAction(value: 0))
        return actions
    }

    public func transition(from state: State, after action: Action) -> [Transition] {
        var transitions: [Transition] = []
        transitions.reserveCapacity(2)

        // Tail. Reward is always zero.
        transitions.append(Transition(
            probability: 1 - probabilityOfHead,
            reward: 0.0,
            newState: State(index: max(state.index - action.value, 0))
        ))

        // Head.
        let maxValue = context.maxValue
        if state.index + action.value >= maxValue {
            transitions.append(Transition(
                probability: probabilityOfHead,
                reward: 1.0,
                newState: State(index: maxValue)
            ))
        } else {
            transitions.append(Transition(
                probability: probabilityOfHead,
                reward: 0.0,
                newState: State(index: state.index + action.value)
            ))
        }
        return transitions
    }
}
