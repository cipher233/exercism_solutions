#include "rna_transcription.h"

#include <string>
#include <map>

namespace rna_transcription {

namespace {

const std::map<char, char> DNA2RNA {
    {'G', 'C'},
    {'C', 'G'},
    {'T', 'A'},
    {'A', 'U'},
};

}
// TODO: add your solution here
char to_rna(char dna) {
    return DNA2RNA.at(dna);
}
    
std::string to_rna(std::string_view dna) {
    std::string rna;
    for (const auto c : dna) {
        rna += DNA2RNA.at(c);
    }
    return rna;
}
    
}  // namespace rna_transcription
