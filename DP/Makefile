BIN = build
CXX = clang++
CLANG_FORMAT = clang-format -i -style=Google

CXXFLAGS += -Wall -std=c++14 -I.

SRCS := $(shell find . -type f -name '*.cpp')
OBJ_FILES := $(patsubst %,${BIN}/%,$(SRCS:.cpp=.o))
HEADERS := $(shell find . -type f -name '*.h')

.PHONY: PolicyEvaluation

PolicyEvaluation: ${BIN} ${BIN}/PolicyEvaluation


${BIN}/PolicyEvaluation: ${BIN}/PolicyEvaluation.o ${BIN}/GridWorldPolicy.o ${BIN}/GridWorldModel.o
	${CXX} -o $@ $^

${BIN}:
	mkdir -p ${BIN}

${BIN}/%.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

clean:
	rm -rf ${BIN}

fmt:
	find . -type f | grep -E "(.h|.cpp)$$" | xargs ${CLANG_FORMAT} ;
