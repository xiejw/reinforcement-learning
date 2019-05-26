import DynamicProgramming

enum GridWorldAction: Int, Action {
    case up = 0
    case down = 1
    case left = 2
    case right = 3

    var value: Int {
        return self.rawValue
    }
}
