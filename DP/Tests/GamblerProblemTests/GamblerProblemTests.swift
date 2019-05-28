import DynamicProgramming
import GamblerProblemLibrary
import XCTest

class GamblerProblemTests: XCTestCase {
    func testFinalResult() {
        let context = Context(stateCount: 100 + 1)
        let model = GamblerProblemModel(context: context, probabilityOfHead: 0.25)
        let evaluator = PolicyEvaluator(model: model, inPlaceUpdate: false)

        let policy = GreedyPolicy(model: model)
        let valueFunction = ValueFunction(stateCount: context.stateCount)

        // Outer loop: Iterate until policy is stable.
        var iteration = 0, maxDelta: FloatType
        repeat {
            iteration += 1

            _ = policy.Adapt(from: valueFunction)
            maxDelta = evaluator.Evaluation(valueFunction, using: policy)
        } while maxDelta >= 0.0001

        let expectedPolicyOutput = """
            1     2     3     4     5     6     7     8     9    10
           11    12    12    11    10     9     8     7     6     5
            4     3     2     1    25     1     2     3     4     5
            6     7     8     9    10    11    12    12    11    10
            9     8     7     6     5     4     3     2     1    50
            1     2     3     4     5     6     7     8     9    10
           11    12    12    11    10     9     8     7     6     5
            4     3     2     1    25     1     2     3     4     5
            6     7     8     9    10    11    12    12    11    10
            9     8     7     6     5     4     3     2     1   n/a

       """
        XCTAssertEqual(
						expectedPolicyOutput,
						policy.debugString(with: context, itemCountPerLine: 10)
        )
    }
}

extension GamblerProblemTests {
    static var allTests = [
        ("testFinalResult", testFinalResult),
    ]
}
