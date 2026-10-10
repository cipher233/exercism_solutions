#include "prime_factors.h"

namespace prime_factors {


// TODO: add your solution here
std::vector<long long> of(long long number) {
    std::vector<long long> factors;
    if (number <= 1) return factors;

    while (number % 2 == 0) {
        factors.push_back(2);
        number /= 2;
    }
    for (long long divisor = 3; divisor <= number / divisor; divisor += 2) {
        while (number % divisor == 0) {
            factors.push_back(divisor);
            number /= divisor;
        }
    }
    if (number > 1) factors.push_back(number);
    return factors;
}
}  // namespace prime_factors
