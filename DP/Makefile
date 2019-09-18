default: PolicyEvaluation PolicyIteration ValueIteration GamblerProblem

include ../Makefile.template

# {{{1 Object files.

POLICY_EVALUATION_LIBS += ${BIN}/Lib/DP/PolicyEvaluator.o
POLICY_EVALUATION_LIBS += ${BIN}/Lib/GridWorld/Model.o
POLICY_EVALUATION_LIBS += ${BIN}/Lib/GridWorld/Policy.o

POLICY_ITERATION_LIBS += ${BIN}/Lib/DP/GreedyPolicy.o
POLICY_ITERATION_LIBS += ${BIN}/Lib/DP/PolicyEvaluator.o
POLICY_ITERATION_LIBS += ${BIN}/Lib/GridWorld/Model.o
POLICY_ITERATION_LIBS += ${BIN}/Lib/GridWorld/Policy.o

VALUE_ITERATION_LIBS += ${BIN}/Lib/DP/GreedyPolicy.o
VALUE_ITERATION_LIBS += ${BIN}/Lib/DP/PolicyEvaluator.o
VALUE_ITERATION_LIBS += ${BIN}/Lib/GridWorld/Model.o
VALUE_ITERATION_LIBS += ${BIN}/Lib/GridWorld/Policy.o

GAMBLER_PROBLEM_LIBS += ${BIN}/Lib/DP/GreedyPolicy.o
GAMBLER_PROBLEM_LIBS += ${BIN}/Lib/DP/PolicyEvaluator.o
GAMBLER_PROBLEM_LIBS += ${BIN}/Lib/GamblerProblem/Model.o
GAMBLER_PROBLEM_LIBS += ${BIN}/Lib/GamblerProblem/Policy.o

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


${BIN}/GamblerProblem: ${BIN}/GamblerProblem.o ${GAMBLER_PROBLEM_LIBS}
	${CXX} -o $@ $^

