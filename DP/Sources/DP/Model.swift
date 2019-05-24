public struct Transition {
    let probability: FloatType
    let reward: FloatType
    let newState: State
}

public protocol Model {
    func isTerminal(for state: State) -> Bool
    func transition(from state: State, after action: Action) -> [Transition]
    var states: [State] { get }
}
