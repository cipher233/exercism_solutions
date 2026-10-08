#include "bob.h"

#include <cctype>

namespace bob {

// TODO: add your solution here
std::string hey(std::string const& phrase) {
    bool has_non_space = false;
    bool ends_with_question = false;
    bool has_letter = false;
    bool has_lowercase = false;

    for (unsigned char c : phrase) {
        if (!std::isspace(c)) {
            has_non_space = true;
            ends_with_question = (c == '?');
        }

        if (std::isalpha(c)) {
            has_letter = true;
            if (std::islower(c)) {
                has_lowercase = true;
            }
        }
    }

    const bool is_yelling = has_letter && !has_lowercase;

    if (!has_non_space) {
        return "Fine. Be that way!";
    }
    if (ends_with_question && is_yelling) {
        return "Calm down, I know what I'm doing!";
    }
    if (ends_with_question) {
        return "Sure.";
    }
    if (is_yelling) {
        return "Whoa, chill out!";
    }
    return "Whatever.";
}
}  // namespace bob
