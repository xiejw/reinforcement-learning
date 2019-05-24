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

public protocol Model {
    func isTerminal(for state: State) -> Bool
    func transition(from state: State, after action: Action) -> [Transition]
    var states: [State] { get }
}
