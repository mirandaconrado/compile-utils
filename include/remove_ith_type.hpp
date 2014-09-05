// Source:
// http://stackoverflow.com/questions/14852593/removing-the-first-type-of-a-stdtuple
#ifndef __COMPILE_UTILS__REMOVE_ITH_TYPE_HPP__
#define __COMPILE_UTILS__REMOVE_ITH_TYPE_HPP__

namespace CompileUtils {
  template <size_t I, class T> struct remove_ith_type { };

  template <class T, class... Ts>
    struct remove_ith_type<0, std::tuple<T, Ts...>> {
      using type = std::tuple<Ts...>;
    };

  template <size_t I, class T, class... Ts>
    struct remove_ith_type<I, std::tuple<T, Ts...>> {
      using type = decltype(
          std::tuple_cat(
            std::declval<std::tuple<T>>(),
            std::declval<typename remove_ith_type<I-1,
                                                  std::tuple<Ts...>>::type>()
            )
          );
    };
};

#endif
