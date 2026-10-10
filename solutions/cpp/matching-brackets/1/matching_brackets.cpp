#include "matching_brackets.h"

#include <cstddef>
#include <vector>

namespace matching_brackets {

// TODO: add your solution here
bool check(std::string const& s) {
    std::vector<char> expected_closers;

    for (char c : s) {
        if (c == '(') {
            expected_closers.push_back(')');
        } else if (c == '[') {
            expected_closers.push_back(']');
        } else if (c == '{') {
            expected_closers.push_back('}');
        } else if (c == ')' || c == ']' || c == '}') {
            if (expected_closers.empty() || expected_closers.back() != c) {
                return false;
            }
            expected_closers.pop_back();
        }
  }

  return expected_closers.empty();
}
}  // namespace matching_brackets
