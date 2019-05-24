public protocol Policy {
    /// Returns the probablity of each action.
    func feasibleActions(for state: State) -> [(probability: FloatType, action: Action)]
}
