public struct Context {
    /// Total number of states in the Gambler Problem model.
    public let stateCount: Int

    /// The maximum value to be achievd, i.e., the goal.
    public let maxValue: Int

    public init(stateCount: Int) {
        precondition(stateCount > 0)
        self.stateCount = stateCount

        self.maxValue = stateCount - 1
    }
}
