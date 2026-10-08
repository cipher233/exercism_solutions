#include "atbash_cipher.h"

#include <cctype>
#include <cstddef>

using std::size_t;

namespace atbash_cipher {

// TODO: add your solution here
// y->b  'z' - 'y' + 'a';
// b->y  'z' - 'b' + 'a';
std::string encode(std::string const& plain) {
    std::string cipher;
    int count = 0;
    for(size_t i = 0; i < plain.size(); ++i) {
        char c = plain[i];
        if (count == 5 && i < plain.size() - 1) {
            cipher += ' ';
            count = 0;
        }
        if (std::isalpha(c)) {
            cipher += 'z' - std::tolower(c) + 'a';
            ++count;
        }
        if (std::isdigit(c)) {
            cipher += c;
            ++count;
        }     
    }
    return cipher;
}
    
std::string decode(std::string const& cipher) {
    std::string plain;
    for (char c : cipher) {
        if (std::isalpha(c)) {
            plain += 'z' - c + 'a';
        }
        if (std::isdigit(c)) {
            plain += c;
        }
    }
    return plain;
}
}  // namespace atbash_cipher
