public struct Context {
    public let stateCount: Int
    let gridSize: Int

    public init(stateCount: Int) {
        self.stateCount = stateCount

        self.gridSize = Int(Double(stateCount).squareRoot())
        precondition(self.gridSize * self.gridSize == stateCount)
    }
}
