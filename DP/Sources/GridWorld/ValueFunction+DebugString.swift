import DynamicProgramming
import Foundation

extension ValueFunction {
    public func debugString(with context: Context) -> String {
        var output = ""
        let gridSize = context.gridSize
        for i in 0 ..< gridSize {
            for j in 0 ..< gridSize {
                output.append(
                    String(format: "%6.2f ", self[GridWorldState(index: i * gridSize + j)]))
            }
            output.append("\n")
        }
        return output
    }
}
