#ifndef __COMPILE_UTILS__BINARY_COMBINATION_HPP__
#define __COMPILE_UTILS__BINARY_COMBINATION_HPP__

namespace CompileUtils {
  template <class Mixer, class T, T v1, T... vals>
    struct binary_combination {
      static constexpr T value = Mixer::template apply<v1,
                       binary_combination<Mixer, T, vals...>::value>::value;
    };

  template <class Mixer, class T, T v1>
    struct binary_combination<Mixer, T, v1> {
      static constexpr T value = v1;
    };


  template <bool... vals> struct and_ {
    template <bool v1, bool v2>
      struct apply { static constexpr bool value = v1 && v2; };

    static constexpr bool value = binary_combination<and_, bool, vals...>::value;
  };
};

#endif
