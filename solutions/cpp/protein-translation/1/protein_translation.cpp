#include "protein_translation.h"

#include<cstddef>
#include<unordered_map>
#include<vector>
#include<string>

namespace protein_translation {

using count_t = std::size_t;
using pos_t = std::size_t;

const std::unordered_map<std::string, std::string> CodonTable {
    {"AUG", "Methionine"},
    {"UUU", "Phenylalanine"},
    {"UUC", "Phenylalanine"},
    {"UUA", "Leucine"},
    {"UUG", "Leucine"},
    {"UCU", "Serine"},
    {"UCC", "Serine"},
    {"UCA", "Serine"},
    {"UCG", "Serine"},
    {"UAU", "Tyrosine"},
    {"UAC", "Tyrosine"},
    {"UGU", "Cysteine"},
    {"UGC", "Cysteine"},
    {"UGG", "Tryptophan"},
    {"UAA", "STOP"},
    {"UAG", "STOP"},
    {"UGA", "STOP"},
};

// TODO: add your solution here
std::vector<std::string> proteins(std::string const& rna) {
    if (rna.size() < 3 || (rna.size() % 3) != 0) {
        return {};
    }
    std::vector<std::string> amino_acids;
    for (pos_t i = 0; i < rna.size(); i += 3) {
        std::string codon = rna.substr(i, count_t(3));
        auto it = CodonTable.find(codon);
        if (it == CodonTable.end()) {
            return {};
        }
        std::string const& amino = it->second;
        if (amino == "STOP") {
            return amino_acids;
        }
        amino_acids.emplace_back(amino);
        // if (CodonTable.count(codon)) {
        //     std::string amino = CodonTable[codon];
        //     if (amino == "STOP") {
        //         return amino_acids;
        //     }
        //     amino_acids.emplace_back(amino);
        // } else {
        //     return {};
        // }
    }
    return amino_acids;
}
}  // namespace protein_translation
