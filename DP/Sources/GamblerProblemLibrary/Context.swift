public struct Context {
    public let stateCount: Int
    public let maxValue: Int

    public init(stateCount: Int) {
        precondition(stateCount > 0)
        self.stateCount = stateCount

        self.maxValue = stateCount - 1
    }
}
