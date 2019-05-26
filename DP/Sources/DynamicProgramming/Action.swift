/// Represents the action taking by the policy.
public protocol Action {
    /// integer value is used for comparison. All negative values are reserved for `SpecialAction`.
    var value: Int { get }
}

enum SpecialAction: Int, Action {
    case notAvailable = -1

    var value: Int {
        return self.rawValue
    }
}
