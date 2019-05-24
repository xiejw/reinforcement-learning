import DynamicProgramming

struct GridWorldState: State {
    private let stateIndex: Int

    init(index: Int) {
        self.stateIndex = index
    }

    var index: Int { return stateIndex }
}
