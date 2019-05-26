import DynamicProgramming
import GridWorld
import XCTest

class PolicyIterationTests: XCTestCase {
    func testFinalResult() {
        let maxLoopCount = 50
        let stateCount = 16
        let context = Context(stateCount: stateCount)
        let model = GridWorldModel(context: context)
        let evaluator = PolicyEvaluator(model: model, inPlaceUpdate: true)

        let policy = GreedyPolicy(model: model)

        var valueFunction = ValueFunction(stateCount: context.stateCount)
        // Outer loop: Iterate until policy is stable.
        var iteration = 0
        while true {
            iteration += 1

            // Use new ValueFunction for each iteration.
            valueFunction = ValueFunction(stateCount: context.stateCount)

            // Inner loop: Iterate until ValueFunction is converged.
            var innerLoopIteration = 0, maxDelta: FloatType
            repeat {
                innerLoopIteration += 1
                maxDelta = evaluator.Evaluation(valueFunction, using: policy)
                if innerLoopIteration > maxLoopCount {
                    break
                }
            } while maxDelta > 0.0001

            if !policy.Adapt(from: valueFunction) {
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

extension PolicyIterationTests {
    static var allTests = [
        ("testFinalResult", testFinalResult),
    ]
}
