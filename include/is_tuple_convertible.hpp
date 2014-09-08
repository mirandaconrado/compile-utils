#ifndef __COMPILE_UTILS__IS_TUPLE_CONVERTIBLE_HPP__
#define __COMPILE_UTILS__IS_TUPLE_CONVERTIBLE_HPP__

#include <boost/integer/static_min_max.hpp>
#include <tuple>

namespace CompileUtils {
  template <size_t I, class From, class To>
    struct is_tuple_convertible_ {
      static constexpr bool value =
        std::is_convertible<
        typename std::tuple_element<I-1,From>::type,
                 typename std::tuple_element<I-1,To>::type
                   >::value && is_tuple_convertible_<I-1,From,To>::value;
    };

  template <class From, class To>
    struct is_tuple_convertible_<0, From, To> {
      static constexpr bool value = true;
    };

  template <class From, class To>
    struct is_tuple_convertible {
      static constexpr bool value =
        std::tuple_size<From>::value == std::tuple_size<To>::value &&
        is_tuple_convertible_<std::tuple_size<From>::value, From, To>::value;
    };
};

#endif
