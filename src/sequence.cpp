#include "sequence.hpp"

namespace {
  template <class F, class T, size_t... S>
    void call(F f, T tuple,
        typename CompileUtils::sequence<S...>) {
      f(std::get<S>(tuple)...);
    }

  void example() {
    auto tuple = std::make_tuple("%d\n", 2);
    call(printf, tuple,
        CompileUtils::tuple_sequence_generator<decltype(tuple)>::type());
  }
};
