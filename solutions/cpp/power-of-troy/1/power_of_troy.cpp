#include "power_of_troy.h"

#include <utility>

namespace troy {

void give_new_artifact(human& h, std::string name) {
    h.possession = std::make_unique<artifact>(name);
}

void exchange_artifacts(std::unique_ptr<artifact>& lhs, std::unique_ptr<artifact>& rhs) {
    std::swap(lhs, rhs);
}

void manifest_power(human& h, std::string s) {
    h.own_power = std::make_shared<power>(s);
}

void use_power(human const& lhs, human& rhs) {
    rhs.influenced_by = lhs.own_power;
}

int power_intensity(human const& h) {
    return static_cast<int>(h.own_power.use_count());
}
}  // namespace troy
