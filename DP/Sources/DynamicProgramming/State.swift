/// Represents the state in the environment.
///
/// The index must be contiguous and starts with 0.
public struct State {
    private let stateIndex: Int

    public init(index: Int) {
        assert(index >= 0)
        self.stateIndex = index
    }

    public var index: Int { return stateIndex }
}
