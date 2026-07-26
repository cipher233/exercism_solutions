#pragma once
#include <unordered_set>
#include <string>
#include <utility>
#include <vector>

namespace allergies {

// TODO: add your solution here
class allergy_test {
    public:
        allergy_test(unsigned int score):allergy_score{score}{}
        bool is_allergic_to(const std::string &item) const;
        std::unordered_set<std::string> get_allergies() const;
    private:
        inline static const std::vector<std::pair<std::string, unsigned int>> allergy_lists {
            {"eggs", 1},
            {"peanuts", 2},
            {"shellfish", 4},
            {"strawberries", 8},
            {"tomatoes", 16},
            {"chocolate", 32},
            {"pollen", 64},
            {"cats", 128},
        };
        unsigned int allergy_score{};
        
};

}  // namespace allergies
