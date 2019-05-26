/// Represents a transition after taking an action.
public struct Transition {
    let probability: FloatType
    let reward: FloatType
    let newState: State

    public init(probability: FloatType, reward: FloatType, newState: State) {
        self.probability = probability
        self.reward = reward
        self.newState = newState
    }
}

/// The model of the environment.
public protocol Model {
    /// Returns true if the state is a terminal state.
    func isTerminal(for state: State) -> Bool

    /// Returns all possible transitions.
    ///
    /// The summation of probabilities of all transitions must be 1 forming a valid distribution.
    func transition(from state: State, after action: Action) -> [Transition]

    /// Returns all possible states in the model.
    var states: [State] { get }

    /// Returns all feasible actions for the state.
    func feasibleActions(for state: State) -> [Action]
}
