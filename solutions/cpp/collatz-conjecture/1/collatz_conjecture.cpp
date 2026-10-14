#include "collatz_conjecture.h"

#include <stdexcept>

namespace collatz_conjecture {

// TODO: add your solution here
int steps(int n) {
    if (n < 1) {
        throw std::domain_error("error");
    }
    int count = 0;
    while (n > 1) {
        if (n & 01) {
            n = n * 3 + 1;
        }else {
            n >>= 1;
        }
        ++count;
    }
    return count;
}
}  // namespace collatz_conjecture
