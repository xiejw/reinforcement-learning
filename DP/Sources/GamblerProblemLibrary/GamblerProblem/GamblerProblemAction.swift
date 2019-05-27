import DynamicProgramming

public struct GamblerProblemAction: Action {
    public let value: Int

    public init(value: Int) {
        assert(value >= 0)
        self.value = value
    }
}
