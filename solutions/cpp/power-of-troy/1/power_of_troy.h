#pragma once

#include <string>
#include <memory>

namespace troy {

struct artifact {
    // constructors needed (until C++20)
    artifact(std::string name) : name(name) {}
    std::string name;
};

struct power {
    // constructors needed (until C++20)
    power(std::string effect) : effect(effect) {}
    std::string effect;
};

struct human {
    // human(): possession{nullptr}, own_power{nullptr}, influenced_by{nullptr} {}
    std::unique_ptr<artifact> possession;
    std::shared_ptr<power> own_power;
    std::shared_ptr<power> influenced_by;
};

void give_new_artifact(human& h, std::string name);

void exchange_artifacts(std::unique_ptr<artifact>& lhs, std::unique_ptr<artifact>& rhs);

void manifest_power(human& h, std::string s);

void use_power(human const& lhs, human& rhs);

int power_intensity(human const& h);
}  // namespace troy
