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

.PHONY: PolicyEvaluation

PolicyEvaluation: ${BIN} ${BIN}/PolicyEvaluation


${BIN}/PolicyEvaluation: ${BIN}/PolicyEvaluation.o ${POLICY_EVALUATION_LIBS}
	${CXX} -o $@ $^

${BIN}:
	mkdir -p ${BIN} ${BIN}/Lib

${BIN}/%.o: %.cpp ${HEADERS}
	${CXX} ${CXXFLAGS} -c -o $@ $<

clean:
	rm -rf ${BIN}

fmt:
	find . -type f | grep -E "(.h|.cpp)$$" | xargs ${CLANG_FORMAT} ;
