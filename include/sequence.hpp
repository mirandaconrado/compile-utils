// Source:
// http://stackoverflow.com/questions/7858817/unpacking-a-tuple-to-call-a-matching-function-pointer/7858971#7858971

#ifndef __COMPILE_UTILS__SEQUENCE_HPP__
#define __COMPILE_UTILS__SEQUENCE_HPP__

#include <tuple>

namespace CompileUtils {
  template <size_t...> struct sequence {};
  template <size_t N, size_t... S>
    struct sequence_generator: sequence_generator<N-1, N-1, S...> {};

  template <size_t... S>
    struct sequence_generator<0, S...> {
      using type = sequence<S...>;
    };

  template <class T>
    struct tuple_sequence_generator {
      using type = typename sequence_generator<std::tuple_size<T>::value>::type;
    };
};

#endif
