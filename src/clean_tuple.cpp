#include "clean_tuple.hpp"

#include <type_traits>

namespace {
  typedef std::tuple<int, int> tuple_type;
  typedef std::tuple<int const, int const&> tuple_type2;
  static_assert(!std::is_same<tuple_type, tuple_type2>::value,
      "Should be the same");
  tuple_type tuple = CompileUtils::clean_tuple<int const, int const&>::type();
  tuple_type tuple2 = CompileUtils::clean_tuple_from_tuple<tuple_type2>::type();
};
