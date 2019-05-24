import DynamicProgramming
import Foundation

extension ValueFunction {
    public func PrintDebugString(context: Context) {
        let gridSize = context.gridSize
        for i in 0 ..< gridSize {
            for j in 0 ..< gridSize {
                let output = String(format: "%6.2f ", self[GridWorldState(index: i * gridSize + j)])
                print(output, terminator: "")
            }
            print("")
        }
    }
}
