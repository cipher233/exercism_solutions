#include "rotational_cipher.h"

namespace rotational_cipher {

namespace {

bool is_ascii_alpha(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool is_ascii_upper(char c) { return c >= 'A' && c <= 'Z'; }

char rot(char const c, int const shift) {
  char const base = is_ascii_upper(c) ? 'A' : 'a';
  return static_cast<char>(base + (c - base + shift) % 26);
}
}  // namespace

// TODO: add your solution here 
std::string rotate(std::string const& plain, int const key) {
  int shift = key % 26;
  if (shift < 0) {
    shift += 26;
  }
  std::string cipher;
  cipher.reserve(plain.size());
  for (char c : plain) {
    cipher += is_ascii_alpha(c) ? rot(c, shift) : c;
  }
  return cipher;
}
}  // namespace rotational_cipher
