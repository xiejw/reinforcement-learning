import DynamicProgramming
import GridWorld
import XCTest

class PolicyEvaluationTests: XCTestCase {
    func testFinalResult() {
        let stateCount = 16
        let context = Context(stateCount: stateCount)
        let model = GridWorldModel(context: context)
        let policy = GridWorldRandomPolicy()

        let valueFunction = ValueFunction(stateCount: context.stateCount)
        let evaluator = PolicyEvaluator(model: model)

        var maxDelta: FloatType
        repeat {
            maxDelta = evaluator.Evaluation(valueFunction, using: policy)
        } while maxDelta > 0.0001

        let expectedValues: [FloatType] = [
            0.00, -14.00, -20.00, -22.00,
            -14.00, -18.00, -20.00, -20.00,
            -20.00, -20.00, -18.00, -14.00,
            -22.00, -20.00, -14.00, 0.00,
        ]

        for i in 0 ..< stateCount {
            XCTAssertEqual(
                expectedValues[i],
                valueFunction[GridWorldState(index: i)],
                accuracy: 0.01
            )
        }
    }
}

extension PolicyEvaluationTests {
    static var allTests = [
        ("testFinalResult", testFinalResult),
    ]
}
