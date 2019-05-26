import DynamicProgramming

/// The model for the GridWorld.
///
/// For each action hitting the boundary, it stays.
public class GridWorldModel: Model {
    private let context: Context

    public init(context: Context) {
        self.context = context
    }

    public func isTerminal(for state: State) -> Bool {
        return state.index == 0 || state.index == context.stateCount - 1
    }

    public func feasibleActions(for state: State) -> [Action] {
        assert(!isTerminal(for: state))
        return [
            GridWorldAction.up,
            GridWorldAction.down,
            GridWorldAction.left,
            GridWorldAction.right,
        ]
    }

    public func transition(from state: State, after action: Action) -> [Transition] {
        let stateIndex = state.index
        let gridSize = context.gridSize

        // For GridWorld, we assume the state index is contiguous.
        assert(stateIndex >= 0 && stateIndex < context.stateCount)

        guard let gridWorldAction = action as? GridWorldAction else {
            fatalError("Action must be GridWorldActio.n")
        }

        var x = stateIndex / gridSize
        var y = stateIndex % gridSize

        switch gridWorldAction {
        case .up: if x > 0 { x -= 1 }
        case .down: if x < gridSize - 1 { x += 1 }
        case .left: if y > 0 { y -= 1 }
        case .right: if y < gridSize - 1 { y += 1 }
        }

        return [
            Transition(
                probability: 1.0,
                reward: -1.0,
                newState: GridWorldState(index: x * gridSize + y)
            ),
        ]
    }

    private lazy var modelStates: [State] = {
        var modelStates: [State] = []
        modelStates.reserveCapacity(context.stateCount)
        for i in 0 ..< context.stateCount {
            modelStates.append(GridWorldState(index: i))
        }
        return modelStates
    }()

    public var states: [State] { return modelStates }
}
