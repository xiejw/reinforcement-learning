import DynamicProgramming

public struct GridWorldState: State {
    private let stateIndex: Int

    public init(index: Int) {
        self.stateIndex = index
    }

    public var index: Int { return stateIndex }
}
