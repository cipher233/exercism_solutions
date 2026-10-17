#include "say.h"

#include <stdexcept>
#include <cstddef>

namespace say {

namespace {

const char* const kOnes[] = {
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine"
};

const char* const kTeens[] = {
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

const char* const kTens[] = {
    "", "", "twenty", "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety"
};

const char* const kScales[] = { "", " thousand", " million", " billion" };

// 0 .. 99
std::string under_hundred(long long n) {
    if (n < 10)  return kOnes[n];
    if (n < 20)  return kTeens[n - 10];

    std::string s = kTens[n / 10];
    if (n % 10 != 0) {
        s += '-';
        s += kOnes[n % 10];
    }
    return s;
}

// 0 .. 999
std::string under_thousand(long long n) {
    std::string s;
    if (n >= 100) {
        s += kOnes[n / 100];
        s += " hundred";
        n %= 100;
        if (n != 0) s += ' ';
    }
    if (n > 0) s += under_hundred(n);
    return s;
}

}
// TODO: add your solution here
std::string in_english(long long number) {
    constexpr long long kLimit = 999'999'999'999LL;
    if (number > kLimit || number < 0) {
        throw std::domain_error("number must be within 0 ~ 999'999'999'999LL");
    }

    if (number == 0) return "zero";
    
    std::string parts[4];   // parts[0]=units, [1]=thousand, [2]=million, [3]=billion
    std::size_t idx = 0;
    while (number > 0) {
        long long chunk = number % 1000;
        if (chunk != 0) {
            parts[idx] = under_thousand(chunk) + kScales[idx];
        }
        number /= 1000;
        ++idx;
    }

    std::string out;
    for (int i = 3; i >= 0; --i) {
        if (parts[i].empty()) continue;
        if (!out.empty()) out += ' ';
        out += parts[i];
    }
    return out;
}
    
}  // namespace say
