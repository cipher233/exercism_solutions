#pragma once

// #include <climits>
// #include <limits>
#include <cstdint>
#include <stdexcept>

namespace grains {

// TODO: add your solution here
[[nodiscard]]
constexpr std::uint64_t square(int grain) {
    if (grain < 1 || grain > 64) {
        throw std::domain_error("square must be between 1 and 64");
    }
    return std::uint64_t{1} << (grain - 1);
}

[[nodiscard]]
constexpr std::uint64_t total() {
    // return ULLONG_MAX;
    // return std::numeric_limits<std::uint64_t>::max();
    return UINT64_MAX;
}
}  // namespace grains
