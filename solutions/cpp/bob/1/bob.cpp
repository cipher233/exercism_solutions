#include "bob.h"

#include <cctype>
#include <algorithm>

namespace bob {

namespace {

bool is_silence(std::string const& s) {
    return std::all_of(s.cbegin(), s.cend(), [](unsigned char c)->bool { return std::isspace(c);});
}

bool is_question(std::string const& s){
    for (auto it = s.crbegin(); it != s.crend(); ++it){
        unsigned char c = static_cast<unsigned char>(*it);
        if (std::isspace(c)) {
            continue;
        }
        return c == '?';
    } 
    return false;
}

bool is_yelling(std::string const& s) {
    bool has_letter{false};
    for (unsigned char const c : s) {
        if (std::isalpha(c)) {
            has_letter = true;
            if (std::islower(c)) {
                return false;
            }
        }  
    }
    return has_letter;
}
}

// TODO: add your solution here
std::string hey(std::string const& phrase) {
    if (is_silence(phrase)) {
        return "Fine. Be that way!";
    }
    if (is_question(phrase) && is_yelling(phrase)) {
        return "Calm down, I know what I'm doing!";
    }
    if (is_question(phrase)) {
        return "Sure.";
    }
    if (is_yelling(phrase)) {
        return "Whoa, chill out!";
    }
    return "Whatever.";   
}
}  // namespace bob
