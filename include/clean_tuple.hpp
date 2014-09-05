#ifndef __COMPILE_UTILS__CLEAN_TUPLE_HPP__
#define __COMPILE_UTILS__CLEAN_TUPLE_HPP__

#include <type_traits>
#include <tuple>

namespace CompileUtils {
  template <class... Types>
    struct clean_tuple {
      using type = std::tuple<
        typename std::remove_const<
        typename std::remove_reference<Types>::type
        >::type...>;
    };

  template <class> struct clean_tuple_from_tuple;

  template <class... Types>
    struct clean_tuple_from_tuple<std::tuple<Types...>> {
      using type = std::tuple<
        typename std::remove_const<
        typename std::remove_reference<Types>::type
        >::type...>;
    };
};

#endif
