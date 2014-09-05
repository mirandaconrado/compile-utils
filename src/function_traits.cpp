#include "function_traits.hpp"

#include <stdio.h>

namespace {
  typedef int(*function_type)(float, char);

  void example() {
    printf("%d\n",
        (CompileUtils::function_traits<function_type>::return_type) 1);

    std::tuple<float,char> tuple =
      CompileUtils::function_traits<function_type>::arg_tuple_type();

    printf("%lu\n", CompileUtils::function_traits<function_type>::arity);
  }
};
