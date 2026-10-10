#include "space_age.h"

#include <cstddef>
#include <array>

namespace space_age {

namespace {

enum class Planet {
    Mercury,
    Venus,
    Earth,
    Mars,
    Jupiter,
    Saturn,
    Uranus,
    Neptune
};

constexpr std::array<double, 8> orbital_periods{
    0.2408467,   // Mercury
    0.61519726,  // Venus
    1.0,         // Earth
    1.8808158,   // Mars
    11.862615,   // Jupiter
    29.447498,   // Saturn
    84.016846,   // Uranus
    164.79132    // Neptune
};

constexpr double orbitalPeriod(Planet planet) {
    return orbital_periods[static_cast<std::size_t>(planet)];
}

}

// TODO: add your solution here
long long space_age::seconds() const noexcept {
    return seconds_;
}

double space_age::ageOn(double orbital_period) const noexcept {
    return static_cast<double>(seconds_) / EarthYear / orbital_period;
}

double space_age::on_earth() const noexcept {
    return ageOn(orbitalPeriod(Planet::Earth));
}

double space_age::on_mercury() const noexcept {
    return ageOn(orbitalPeriod(Planet::Mercury));
}

double space_age::on_venus() const noexcept {
    return ageOn(orbitalPeriod(Planet::Venus));
}

double space_age::on_mars() const noexcept {
    return ageOn(orbitalPeriod(Planet::Mars));
}

double space_age::on_jupiter() const noexcept {
    return ageOn(orbitalPeriod(Planet::Jupiter));
}

double space_age::on_saturn() const noexcept {
    return ageOn(orbitalPeriod(Planet::Saturn));
}

double space_age::on_uranus() const noexcept {
    return ageOn(orbitalPeriod(Planet::Uranus));
}

double space_age::on_neptune() const noexcept {
    return ageOn(orbitalPeriod(Planet::Neptune));
}

}  // namespace space_age
