#include "difference_of_squares.h"

namespace difference_of_squares {

// TODO: add your solution here
unsigned long long square_of_sum(unsigned long long n) {
    // unsigned long long ans{};
    // for (unsigned long long i = 1; i <= n; ++i) {
    //     ans += i;
    // }
    auto const sum = n * (n + 1) / 2;
    return sum * sum;
}

unsigned long long sum_of_squares(unsigned long long n) {
    // unsigned long long ans{};
    // for (unsigned long long i = 1; i <= n; ++i) {
    //     ans += i * i;
    // }
    // return ans;
     return n * (n + 1) * (2 * n + 1) / 6;
}

unsigned long long difference(unsigned long long n) {
    return square_of_sum(n) - sum_of_squares(n);
}
}  // namespace difference_of_squares
