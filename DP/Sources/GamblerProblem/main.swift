/// Gambler Problem.
///
/// The result depends on the action search order. In particular, for any greed
/// policy selection, if the value function is converged already, then action 0
/// (stake 0, i.e., no bet) is always one of the best actions. So, we should
/// consider 0 as the last action by placing it in the end of action search
/// order.
///
/// Check GamblerProblemModel file and look for FeasiableActions for details.
///
/// In addition, for numerical program, it is up to the precision whether action
/// 0 will be the best. So, using double is important. For probabiliby_head =
/// 0.75, the system might favor non-zero action due to super tiny accuracy issue
/// during the convergence process.
import DynamicProgramming
import GamblerProblemLibrary

let context = Context(stateCount: 100 + 1)
let model = GamblerProblemModel(context: context, probabilityOfHead: 0.25)
let evaluator = PolicyEvaluator(model: model, inPlaceUpdate: false)

let policy = GreedyPolicy(model: model)
let valueFunction = ValueFunction(stateCount: context.stateCount)

// Outer loop: Iterate until value function is stable.
var iteration = 0, maxDelta: FloatType
repeat {
    iteration += 1

    print("Iteration \(iteration)")

    _ = policy.Adapt(from: valueFunction)
    print("New policy:\n\(policy.debugString(with: context))")

    maxDelta = evaluator.Evaluation(valueFunction, using: policy)
    print("maxDelta \(maxDelta)")
} while maxDelta >= 0.0001

print("ValueFunction converged.")
