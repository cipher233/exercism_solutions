#pragma once

#include <type_traits>
#include <map>
#include <string>
#include <string_view>

namespace rna_transcription {
    
const std::map<char, char> DNA2RNA {
    {'G', 'C'},
    {'C', 'G'},
    {'T', 'A'},
    {'A', 'U'},
};
// TODO: add your solution here

template<typename T>
auto to_rna(T dna) {
    if constexpr (std::is_same_v<T, char>){
        return DNA2RNA.at(dna);
    } else {
        std::string_view sv{dna};
        std::string rna;
        rna.reserve(sv.size());
        for (char c : sv) {
            rna += DNA2RNA.at(c);
        }
        return rna;
    }
}
}  // namespace rna_transcription
