#include "repeated_tuple.hpp"

namespace {
  std::tuple<int, int, int> tuple =
    CompileUtils::repeated_tuple<3, int>::type();
};
