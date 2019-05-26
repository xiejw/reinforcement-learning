import DynamicProgramming
import GridWorld
import XCTest

class ValueIterationTests: XCTestCase {
    func testFinalResult() {
        let stateCount = 16
        let context = Context(stateCount: stateCount)
        let model = GridWorldModel(context: context)
        let evaluator = PolicyEvaluator(model: model, inPlaceUpdate: true)

        let policy = GreedyPolicy(model: model)
        let valueFunction = ValueFunction(stateCount: context.stateCount)

        var iteration = 0, maxDelta: FloatType
        while true {
            iteration += 1
            _ = policy.Adapt(from: valueFunction)
            maxDelta = evaluator.Evaluation(valueFunction, using: policy)
            if maxDelta < 0.0001 {
                break
            }
        }

        XCTAssertTrue(iteration < 5)
        let expectedValues: [FloatType] = [
            0.00, -1.00, -2.00, -3.00,
            -1.00, -2.00, -3.00, -2.00,
            -2.00, -3.00, -2.00, -1.00,
            -3.00, -2.00, -1.00, 0.00,
        ]

        for i in 0 ..< stateCount {
            XCTAssertEqual(
                expectedValues[i],
                valueFunction[GridWorldState(index: i)],
                accuracy: 0.01
            )
        }

        let expectedPolicyOutput = """
           n/a  left  left  down
            up    up    up  down
            up    up  down  down
            up right right   n/a

        """
        XCTAssertEqual(expectedPolicyOutput, policy.debugString(with: context, for: model))
    }
}

extension ValueIterationTests {
    static var allTests = [
        ("testFinalResult", testFinalResult),
    ]
}
