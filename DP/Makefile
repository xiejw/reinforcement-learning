FORMATTER=docker run --rm -ti -v `pwd`:/source xiejw/swift-format /swift-format.sh

default: clean test

.PHONY: PolicyEvaluation, PolicyIteration, ValueIteration, GamblerProblem

PolicyEvaluation:
	swift run PolicyEvaluation

PolicyIteration:
	swift run PolicyIteration

ValueIteration:
	swift run ValueIteration

GamblerProblem:
	swift run GamblerProblem

test:
	swift test

fmt:
	${FORMATTER} Sources Tests

clean:
	swift package clean
