#include "allergies.h"

namespace allergies {

// TODO: add your solution here

bool allergy_test::is_allergic_to(const std::string &item) const {
    for (const auto &[name, value] : allergy_lists) {
        if (name == item) {
            return (value & allergy_score) != 0;
        }
    }
    return false;
}

std::unordered_set<std::string> allergy_test::get_allergies() const {
    std::unordered_set<std::string> result;
    for (const auto &[name, value] : allergy_lists) {
        if ((value & allergy_score) != 0) {
            result.emplace(name);
        }
    }
    return result;
}

}  // namespace allergies
