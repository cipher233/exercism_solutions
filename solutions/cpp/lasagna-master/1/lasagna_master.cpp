#include "lasagna_master.h"

namespace lasagna_master {

// TODO: add your solution here
int preparationTime(std::vector<std::string> const& layers, int duration) {
    return duration * layers.size();
}

amount quantities(std::vector<std::string> const& quantity) {
    amount amt{};
    for(std::string const& e : quantity) {
        if (e == "noodles") {
            amt.noodles += 50;
        }
        if (e == "sauce") {
            amt.sauce += 0.2;
        }
    }
    return amt;
}

void addSecretIngredient(std::vector<std::string> &myList, std::vector<std::string> const& friendList) {
    // myList[myList.size() - 1] = friendList.back();
    *(myList.end() - 1) = friendList.back();
}

void addSecretIngredient(std::vector<std::string> &myList, std::string const& secretIngredient) {
    *(myList.end() - 1) = secretIngredient;
}

std::vector<double> scaleRecipe(std::vector<double> const& quantites, int portions) {
    if (portions <= 0) {
        return {};
    }
    double scaleRatio = portions / 2.0;
    std::vector<double> scaleQuantites(quantites.size());
    for (size_t i = 0; i < quantites.size(); ++i) {
        scaleQuantites[i] = quantites[i] * scaleRatio;
    }
    return scaleQuantites;
}


}  // namespace lasagna_master
