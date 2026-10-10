#include "grains.h"

// #include <climits>
#include <limits>
#include <stdexcept>

namespace grains {

// TODO: add your solution here
unsigned long long square(int grain) {
    if (grain < 1 || grain > 64) {
        throw std::domain_error("square must be between 1 and 64");
    }
    return 1ULL << (grain - 1);
}

unsigned long long total() {
    // return ULLONG_MAX;
    return std::numeric_limits<unsigned long long>::max();  
}
}  // namespace grains
