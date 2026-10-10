#include "sieve.h"

namespace sieve {

namespace {

bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i <= n / i; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
}

// TODO: add your solution here
std::vector<int> primes(int number) {
    std::vector<int> ans;
    if (number <= 1) return ans;

    for (int i = 2; i <= number; ++i) {
        if (is_prime(i)) {
            ans.push_back(i);
        }
    }
    return ans;
}
}  // namespace sieve
