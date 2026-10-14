#include "hamming.h"

#include <stdexcept>
#include <cstddef>

namespace hamming {

// TODO: add your solution here
int compute(const std::string& strand1, const std::string& strand2) {
    if (strand1.size() != strand2.size()) {
        throw std::domain_error("compute: Two strand length must be equal.");
    }
    int count = 0;
    for (std::size_t i = 0; i < strand1.size(); ++i) {
        if (strand1[i] ^ strand2[i]) {
            ++count;
        }
    }
    return count;
}
}  // namespace hamming
