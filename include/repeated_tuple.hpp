#ifndef __COMPILE_UTILS__REPEATED_TUPLE_HPP__
#define __COMPILE_UTILS__REPEATED_TUPLE_HPP__

#include <tuple>

namespace CompileUtils {
  template <size_t N, class T, class... Ts>
    struct repeated_tuple_: repeated_tuple_<N-1, T, T, Ts...> { };

  template <class T, class... Ts>
    struct repeated_tuple_<0, T, Ts...> { using type = std::tuple<Ts...>; };

  template <size_t I, class T>
    struct repeated_tuple {
      using type = typename repeated_tuple_<I, T>::type;
    };
};

#endif
