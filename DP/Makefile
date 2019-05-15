BIN = build
CXX = clang++
CLANG_FORMAT = clang-format -i -style=Google

CXXFLAGS += -Wall -std=c++14 -I.

SRCS := $(shell find . -type f -name '*.cpp')
OBJ_FILES := $(patsubst %,${BIN}/%,$(SRCS:.cpp=.o))
HEADERS := $(shell find . -type f -name '*.h')

POLICY_EVALUATION_LIBS += ${BIN}/Lib/GridWorldPolicy.o
POLICY_EVALUATION_LIBS += ${BIN}/Lib/GridWorldModel.o
POLICY_EVALUATION_LIBS += ${BIN}/Lib/PolicyEvaluator.o

POLICY_ITERATION_LIBS += ${BIN}/Lib/GreedyPolicy.o
POLICY_ITERATION_LIBS += ${BIN}/Lib/GridWorldPolicy.o
POLICY_ITERATION_LIBS += ${BIN}/Lib/GridWorldModel.o
POLICY_ITERATION_LIBS += ${BIN}/Lib/PolicyEvaluator.o

VALUE_ITERATION_LIBS += ${BIN}/Lib/GreedyPolicy.o
VALUE_ITERATION_LIBS += ${BIN}/Lib/GridWorldPolicy.o
VALUE_ITERATION_LIBS += ${BIN}/Lib/GridWorldModel.o
VALUE_ITERATION_LIBS += ${BIN}/Lib/PolicyEvaluator.o

GAMBLER_PROBLEM__LIBS += ${BIN}/Lib/GreedyPolicy.o
GAMBLER_PROBLEM__LIBS += ${BIN}/Lib/GamblerProblemPolicy.o
GAMBLER_PROBLEM__LIBS += ${BIN}/Lib/GamblerProblemModel.o
GAMBLER_PROBLEM__LIBS += ${BIN}/Lib/PolicyEvaluator.o

default: fmt PolicyEvaluation PolicyIteration ValueIteration GamblerProblem

# {{{1 PolicyEvaluation
.PHONY: PolicyEvaluation
PolicyEvaluation: ${BIN} ${BIN}/PolicyEvaluation


${BIN}/PolicyEvaluation: ${BIN}/PolicyEvaluation.o ${POLICY_EVALUATION_LIBS}
	${CXX} -o $@ $^

# {{{1 PolicyIteration
.PHONY: PolicyIteration
PolicyIteration: ${BIN} ${BIN}/PolicyIteration


${BIN}/PolicyIteration: ${BIN}/PolicyIteration.o ${POLICY_ITERATION_LIBS}
	${CXX} -o $@ $^

# {{{1 ValueIteration
.PHONY: ValueIteration
ValueIteration: ${BIN} ${BIN}/ValueIteration


${BIN}/ValueIteration: ${BIN}/ValueIteration.o ${VALUE_ITERATION_LIBS}
	${CXX} -o $@ $^

# {{{1 GamblerProblem
.PHONY: GamblerProblem
GamblerProblem: ${BIN} ${BIN}/GamblerProblem


${BIN}/GamblerProblem: ${BIN}/GamblerProblem.o ${GAMBLER_PROBLEM__LIBS}
	${CXX} -o $@ $^

# {{{1 Default Actions.

${BIN}:
	mkdir -p ${BIN} ${BIN}/Lib

${BIN}/%.o: %.cpp ${HEADERS}
	${CXX} ${CXXFLAGS} -c -o $@ $<

# {{{1 Maintenance.

clean:
	rm -rf ${BIN}

fmt:
	find . -type f | grep -E "(.h|.cpp)$$" | xargs ${CLANG_FORMAT} ;
