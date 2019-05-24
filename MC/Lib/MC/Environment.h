#ifndef MODEL
#define MODEL

#include <memory>
#include <tuple>
#include <vector>

namespace MC {

using Reward = double;
using EndOfEpisode = bool;
using Action = int;

class Envinronment {
 public:
  virtual std::tuple<Reward, EndOfEpisode, std::unique_ptr<State>> Next(
      State state, Action action) const = 0;
};

}  // namespace MC

#endif
