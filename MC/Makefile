default: fmt Blackjack

include ../Makefile.template


# BLACKJACK_LIBS += ${BIN}/Lib/BlackjackModel.o


# {{{1 Blackjack
.PHONY: Blackjack
Blackjack: ${BIN} ${BIN}/Blackjack


${BIN}/Blackjack: ${BIN}/Blackjack.o ${BLACKJACK_LIBS}
	${CXX} -o $@ $^

