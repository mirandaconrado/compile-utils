#ifndef __COMPILE_UTILS__CLEAN_TUPLE_HPP__
#define __COMPILE_UTILS__CLEAN_TUPLE_HPP__

namespace CompileUtils {
  template <class... Types>
    struct clean_tuple {
      using type = std::tuple<
        typename std::remove_const<
        typename std::remove_reference<Types>::type
        >::type...>;
    };
};

#endif
