#include "luhn.h"

#include <cstddef>

namespace luhn {
namespace {
inline bool is_digit(char const c) {
    return c >= '0' && c <= '9';
}

}
// TODO: add your solution here
bool valid(std::string const& card) {
    std::size_t digit_count{0};
    int sum{0};
    bool to_double{false};
    for (auto it = card.rbegin(); it != card.rend(); ++it) {
        char const c = *it;
        if (c == ' ') {
            continue;
        }
        if (!is_digit(c)) {
            return false;
        }
        
        int value = c - '0';
        if (to_double) {
            // value *= 2;
            // if (value > 9) {
            //     value -= 9;
            // }
            value = (value * 2) > 9 ? value * 2 - 9 : value * 2;
        }
        sum += value;
        ++digit_count;
        to_double = !to_double;
    }
    return digit_count > 1 && sum % 10 == 0;
}
}  // namespace luhn
