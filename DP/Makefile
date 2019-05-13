BIN = build
CXX = clang++
CLANG_FORMAT = clang-format -i -style=Google

CXXFLAGS += -Wall -std=c++14 -I.

SRCS := $(shell find . -type f -name '*.cpp')
OBJ_FILES := $(patsubst %,${BIN}/%,$(SRCS:.cpp=.o))
HEADERS := $(shell find . -type f -name '*.h')

.PHONY: PolicyEvaluation

PolicyEvaluation: ${BIN} ${BIN}/PolicyEvaluation


${BIN}/PolicyEvaluation: ${BIN}/PolicyEvaluation.o ${BIN}/Lib/GridWorldPolicy.o ${BIN}/Lib/GridWorldModel.o ${BIN}/Lib/PolicyEvaluator.o
	${CXX} -o $@ $^

${BIN}:
	mkdir -p ${BIN} ${BIN}/Lib

${BIN}/Lib/%.o: Lib/%.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

${BIN}/%.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

clean:
	rm -rf ${BIN}

fmt:
	find . -type f | grep -E "(.h|.cpp)$$" | xargs ${CLANG_FORMAT} ;
