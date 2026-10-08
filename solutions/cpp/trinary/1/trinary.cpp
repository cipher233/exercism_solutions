#include "trinary.h"

#include <limits>

namespace trinary {

// TODO: add your solution here
int to_decimal(std::string const& s) {
    int ans{};
    for (char c : s) {
        if (c < '0' || c > '2') {
            return 0;
        }
        int const digit = c - '0';
        if (ans > (std::numeric_limits<int>::max() - digit) / 3) {
            return 0;
        }
        ans = ans * 3 + digit;
    }
    return ans;
}
}  // namespace trinary
