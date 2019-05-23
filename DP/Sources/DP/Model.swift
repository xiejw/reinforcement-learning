typealias State = Int

public struct Transition {
    let probability: FloatType
    let reward: FloatType
    let newState: State
}

public protocol Model {
    func isTerminal(for stateIndex: Int) -> Bool
    func transition(from stateIndex: Int, after action: Action) -> [Transition]
}
