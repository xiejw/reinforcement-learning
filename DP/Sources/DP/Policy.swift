protocol Policy {
    func feasibleActions(for state: State) -> [(FloatType, Action)]
}
