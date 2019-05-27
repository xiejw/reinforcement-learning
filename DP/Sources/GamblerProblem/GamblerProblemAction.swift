import DynamicProgramming

public struct GamblerProblemAction: Action {

    let value: Int

    public init(value: Int) {
        assert(value >= 0)
        self.value = value
    }
}
