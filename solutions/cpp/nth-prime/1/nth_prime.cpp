#include "nth_prime.h"

#include <stdexcept>

namespace nth_prime {

namespace {

bool is_prime(const int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
    
}

// TODO: add your solution here
int nth(int n) {
    if (n < 1) {
        throw std::domain_error("argument must be positive.");
    }
    int count = 0;
    int x = 1;
    while (count < n) {
        ++x;
        if (is_prime(x)) {
            ++count;
        }
    }
    return x;
}
    
}  // namespace nth_prime
