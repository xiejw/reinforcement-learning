#ifndef BLACKJACK_STATE
#define BLACKJACK_STATE

#include "Lib/MC/State.h"

namespace Blackjack {

struct State : public MC::State {
  int current_sum;
  int dealer_showing_card;
  bool usable_ace;
};

}  // namespace Blackjack

#endif
