#pragma once

#include <map>
#include <string_view>

namespace nucleotide_count {

// TODO: add your solution here
std::map<char, int> count(std::string_view chains);
}  // namespace nucleotide_count
