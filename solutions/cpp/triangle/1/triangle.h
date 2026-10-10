#pragma once

// #include <concepts>
#include <stdexcept>
#include <type_traits>

namespace triangle {

enum class flavor {
    equilateral,
    isosceles,
    scalene,
};
// TODO: add your solution here

// template <typename T, typename U, typename V>
// concept ArithmeticTypes =
//     (std::integral<T> || std::floating_point<T>) &&
//     (std::integral<U> || std::floating_point<U>) &&
//     (std::integral<V> || std::floating_point<V>);
    
// template<ArithmeticType T>
template<typename T, typename U, typename V>
    // requires ArithmeticTypes<T, U, V>
flavor kind(T a, U b, V c) {
    static_assert(std::is_arithmetic_v<T>, "Triangle sides must be arithmetic types");
    static_assert(std::is_arithmetic_v<U>, "Triangle sides must be arithmetic types");
    static_assert(std::is_arithmetic_v<V>, "Triangle sides must be arithmetic types");
    if (a <= 0 || b <= 0 || c <= 0) {
        throw std::domain_error("Triangle sides must be positive");
    }
    if (a + b <= c || a + c <= b || c + b <= a) {
        throw std::domain_error("Invalid triangle");
    }
    if (a == b && b == c) {
        return flavor::equilateral;
    }
    if (a == b || a == c || b == c) {
        return flavor::isosceles;
    }
    return flavor::scalene;
}
}  // namespace triangle
