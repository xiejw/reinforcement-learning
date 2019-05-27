FORMATTER=docker run --rm -ti -v `pwd`:/source xiejw/swift-format /swift-format.sh

default: test

.PHONY: policy_evaluation, policy_iteration, value_iteration

policy_evaluation:
	swift run PolicyEvaluation

policy_iteration:
	swift run PolicyIteration

value_iteration:
	swift run ValueIteration

test:
	swift test

fmt:
	${FORMATTER} Sources Tests
