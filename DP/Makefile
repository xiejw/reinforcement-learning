BIN = build
CXX = clang++
CLANG_FORMAT = clang-format -i -style=Google

CXXFLAGS += -Wall -std=c++14 -I.

SRCS := $(shell find . -type f -name '*.cpp')
OBJ_FILES := $(patsubst %,${BIN}/%,$(SRCS:.cpp=.o))

.PHONY: PolicyEvaluation

PolicyEvaluation: ${BIN}/PolicyEvaluation


${BIN}/PolicyEvaluation: ${BIN}/PolicyEvaluation.o
	${CXX} -o $@ $<

${BIN}:
	mkdir -p ${BIN}

${BIN}/%.o: %.cpp ${BIN}
	${CXX} ${CXXFLAGS} -c -o $@ $<
