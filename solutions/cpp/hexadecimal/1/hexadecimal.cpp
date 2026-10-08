#include "hexadecimal.h"

#include <limits>

namespace hexadecimal {

// TODO: add your solution here
int convert(std::string const& input) {
    int value{0};

    for (char c : input) {
        int digit;
        if (c >= '0' && c <= '9') {
            digit = c - '0';
        }else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;
        }else if (c >= 'A' && c <= 'F') {
            digit = c - 'A' + 10;
        }else {
            return 0;
        }
        if (value > (std::numeric_limits<int>::max() - digit) / 16) {
            return 0;
        }
        value = value * 16 + digit;
    }
    return value;
}
}  // namespace hexadecimal
