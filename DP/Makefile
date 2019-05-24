FORMATTER=docker run --rm -ti -v `pwd`:/source xiejw/swift-format /swift-format.sh

default: run

run:
	swift run PolicyEvaluation

fmt:
	${FORMATTER} Sources Tests
