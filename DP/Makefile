FORMATTER=docker run --rm -ti -v `pwd`:/source xiejw/swift-format /swift-format.sh

default: test

policy_evaluation:
	swift run PolicyEvaluation

test:
	swift test

fmt:
	${FORMATTER} Sources Tests
