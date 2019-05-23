public enum Action {}

protocol Policy {
    func feasibleActions(for stateIndex: Int) -> [(FloatType, Action)]
}
