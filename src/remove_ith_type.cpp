#include "remove_ith_type.hpp"

namespace {
  typedef std::tuple<int> tuple1;
  typedef std::tuple<char, int> tuple2;
  tuple1 tuple = CompileUtils::remove_ith_type<0, tuple2>::type();
};
