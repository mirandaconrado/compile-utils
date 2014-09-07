#include "is_tuple_convertible.hpp"

#include <stdio.h>

namespace {
  typedef std::tuple<int, int> tuple1;
  typedef std::tuple<float, float> tuple2;
  typedef std::tuple<float, std::tuple<float>> tuple3;

  static_assert(CompileUtils::is_tuple_convertible<tuple1, tuple2>::value,
      "Tuple values can't be converted");
  static_assert(!CompileUtils::is_tuple_convertible<tuple1, tuple3>::value,
      "Tuple values can be converted");
};
