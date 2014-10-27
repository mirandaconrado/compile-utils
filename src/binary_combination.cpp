#include "binary_combination.hpp"

#include <type_traits>

namespace {
  static_assert(CompileUtils::and_<true,true>::value, "Should be true");
  static_assert(!CompileUtils::and_<false,true>::value, "Should be false");
  static_assert(!CompileUtils::and_<true,false>::value, "Should be false");
  static_assert(!CompileUtils::and_<false,false>::value, "Should be false");
};
