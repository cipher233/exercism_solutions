#include "pangram.h"

#include <cstdint>

namespace pangram {

// TODO: add your solution here
[[nodiscard]] bool is_pangram(std::string const& sentence) {
    std::uint32_t mask = 0;
    constexpr std::uint32_t fullmask = (1u << 26) - 1;
    for (char c : sentence) {
        if (c >= 'A' && c <= 'Z') {
            c = static_cast<char>(c + ('a' - 'A'));
        }
        if (c >= 'a' && c <= 'z') {
            mask |= 1u << (c - 'a');
            if (mask == fullmask) {
                return true;
            }
        }
    }

    return false;
}
}  // namespace pangram
