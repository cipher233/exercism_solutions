#include "atbash_cipher.h"



namespace atbash_cipher {
    
namespace {

bool is_ascii_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_ascii_digit(char c) {
    return c >= '0' && c <= '9';
}

char to_lower_ascii(char c) {
    return c >= 'A' && c <= 'Z' ? c + ('a' - 'A') : c;
}

char atbash(char c) {
    return 'z' - to_lower_ascii(c) + 'a';
}

}
// TODO: add your solution here
// y->b  'z' - 'y' + 'a';
// b->y  'z' - 'b' + 'a';
std::string encode(std::string const& plain) {
    std::string cipher;
    cipher.reserve(plain.size() + plain.size() / 5);

    std::size_t group_size = 0;

    for (char c : plain) {
        if (!is_ascii_letter(c) && !is_ascii_digit(c)) {
            continue;
        }

        if (group_size == 5) {
            cipher += ' ';
            group_size = 0;
        }

        cipher += is_ascii_letter(c) ? atbash(c) : c;
        ++group_size;
    }

    return cipher;
}

std::string decode(std::string const& cipher) {
    std::string plain;
    plain.reserve(cipher.size());

    for (char c : cipher) {
        if (is_ascii_letter(c)) {
            plain += atbash(c);
        } else if (is_ascii_digit(c)) {
            plain += c;
        }
    }

    return plain;
}

}  // namespace atbash_cipher
