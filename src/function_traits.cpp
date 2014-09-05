#include "function_traits.hpp"

#include <stdio.h>

namespace {
  typedef int(*function_type)(float, char);

  static_assert(std::is_same<int,
      CompileUtils::function_traits<function_type>::return_type>::value,
      "Incorrect return type");

  std::tuple<float,char> tuple =
    CompileUtils::function_traits<function_type>::arg_tuple_type();

  static_assert(CompileUtils::function_traits<function_type>::arity == 2,
      "Arity has incorrect value");
};
