import DynamicProgramming

public class GridWorldRandomPolicy: Policy {
    public init() {}

    public func feasibleActions(for _: State) -> [(probability: FloatType, action: Action)] {
        return [
            (probability: 0.25, action: GridWorldAction.up),
            (probability: 0.25, action: GridWorldAction.down),
            (probability: 0.25, action: GridWorldAction.left),
            (probability: 0.25, action: GridWorldAction.right),
        ]
    }
}
