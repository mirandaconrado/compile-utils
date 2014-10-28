#ifndef __COMPILE_UTILS__CLEAN_TYPE_HPP__
#define __COMPILE_UTILS__CLEAN_TYPE_HPP__

#include <type_traits>

namespace CompileUtils {
  template <class T>
    struct clean_type {
      using type = typename std::remove_const<
        typename std::remove_reference<T>::type
        >::type;
    };
};

#endif
