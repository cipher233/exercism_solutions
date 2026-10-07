#pragma once

#include<vector>
#include<string>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(std::vector<std::string> const& layers, int duration = 2);

amount quantities(std::vector<std::string> const& quantity);

void addSecretIngredient(std::vector<std::string> &myList, std::vector<std::string> const& friendList);

void addSecretIngredient(std::vector<std::string> &myList, std::string const& secretIngredient);

std::vector<double> scaleRecipe(std::vector<double> const& quantites, int portions);

}  // namespace lasagna_master
