#ifndef __COMPILE_UTILS__CLEAN_TUPLE_HPP__
#define __COMPILE_UTILS__CLEAN_TUPLE_HPP__

#include "clean_type.hpp"
#include <tuple>

namespace CompileUtils {
  template <class... Types>
    struct clean_tuple {
      using type = std::tuple<typename clean_type<Types>::type...>;
    };

  template <class> struct clean_tuple_from_tuple;

  template <class... Types>
    struct clean_tuple_from_tuple<std::tuple<Types...>> {
      using type = typename clean_tuple<Types...>::type;
    };
};

#endif
