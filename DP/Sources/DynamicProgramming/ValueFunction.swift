/// ValueFunction represents the value estimations for each state.
///
/// The state is accessed via the index of the state.
public class ValueFunction {
    private let stateCount: Int
    private var values: [FloatType]

    private enum Mode {
        case direct
        case buffered
    }

    public init(stateCount: Int) {
        self.stateCount = stateCount
        values = Array(repeating: 0.0, count: stateCount)
    }

    var count: Int { return values.count }
}

extension ValueFunction {
    subscript(state: State) -> FloatType {
        get {
            return values[state.index]
        }
        set(newValue) {
            values[state.index] = newValue
        }
    }
}