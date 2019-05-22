default: fmt PolicyEvaluation PolicyIteration ValueIteration GamblerProblem

include ../Makefile.template

# {{{1 Object files.

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

