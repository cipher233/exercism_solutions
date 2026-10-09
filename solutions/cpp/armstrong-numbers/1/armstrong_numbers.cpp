#include "armstrong_numbers.h"

#include <cmath>

namespace armstrong_numbers {

namespace {
int number_of_digit(int n) {
    int count{0};
    do {
        ++count;
        n /= 10;
    } while (n > 0);
    return count;
}

long long integer_power(int base, int exponent) {
    int result{1};
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

}
// TODO: add your solution here
bool is_armstrong_number(int number) {
    if (number < 0) {
        return false;
    }
    int exponent = number_of_digit(number);
    int remaining = number;
    long long sum{0};
    do {
        int const digit = remaining % 10;
        sum += integer_power(digit, exponent);
        if (sum > number) {
            return false;
        }
        remaining /= 10;
    } while (remaining > 0);

    return sum == number;
}
}  // namespace armstrong_numbers
