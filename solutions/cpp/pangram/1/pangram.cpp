#include "pangram.h"

namespace pangram {

// TODO: add your solution here
bool is_pangram(std::string const& sentence) {
    bool seen[26]{};
    int count{0};
    for (char c : sentence) {
        if (c >= 'A' && c <= 'Z') {
            c = static_cast<char>(c + ('a' - 'A'));
        }
        if (c >= 'a' && c <= 'z') {
            int const index = c - 'a';
            if (!seen[index]) {
                seen[index] = true;
                ++count;
                if (count == 26) {
                    return true;
                }
            }
        }
    }

    return false;
}
}  // namespace pangram
