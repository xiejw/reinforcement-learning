/// Represents the state in the environment.
///
/// The index must be contiguous and starts with 0.
public protocol State {
    var index: Int { get }
}
