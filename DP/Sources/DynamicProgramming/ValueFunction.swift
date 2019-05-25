/// ValueFunction represents the value estimations for each state.
///
/// The state is accessed via the index of the state.
public class ValueFunction {
    private let stateCount: Int
    private var values: [FloatType]
    private var temporaryValuesCopy: [FloatType] = []

    private enum Mode {
        case direct
        case buffered
    }

    private var mode = Mode.direct

    public init(stateCount: Int) {
        self.stateCount = stateCount
        values = Array(repeating: 0.0, count: stateCount)
    }

    var count: Int { return values.count }
}

extension ValueFunction {
    func BeginWriteOnBufferedData() {
        mode = .buffered
        temporaryValuesCopy = values
    }

    func EndWriteOnBufferedData() {
        mode = .direct
        // If we can adjust the ownership, this copy can be saved so we just swap the pointers.
        values = temporaryValuesCopy
    }
}

extension ValueFunction {
    public subscript(state: State) -> FloatType {
        get {
            assert(state.index >= 0 && state.index < stateCount)
            return values[state.index]
        }
        set(newValue) {
            assert(state.index >= 0 && state.index < stateCount)
            switch mode {
            case .direct: values[state.index] = newValue
            case .buffered: temporaryValuesCopy[state.index] = newValue
            }
        }
    }
}
