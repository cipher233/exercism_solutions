#include "nucleotide_count.h"

#include <stdexcept>

namespace nucleotide_count {

// TODO: add your solution here
std::map<char, int> count(std::string_view chains) {
    std::map<char, int> nucleotides_map {
        {'A', 0},
        {'C', 0},
        {'G', 0},
        {'T', 0},
    };
    if (chains.size() == 0) {
        return nucleotides_map;
    }

    for (const auto c : chains) {
        if (!nucleotides_map.count(c)) {
            throw std::invalid_argument("error");
        }
        ++nucleotides_map[c];
    }
    return nucleotides_map;
}
}  // namespace nucleotide_count
