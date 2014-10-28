#include "clean_type.hpp"

#include <type_traits>

namespace {
  typedef int const& T1;
  typedef int T2;
  static_assert(!std::is_same<T1, T2>::value, "Should be the same");
};
