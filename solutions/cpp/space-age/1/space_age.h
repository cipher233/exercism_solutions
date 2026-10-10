#pragma once

namespace space_age {

// TODO: add your solution here
class space_age {
public:
    explicit space_age(long long seconds) noexcept : seconds_{seconds} {}

    long long seconds() const noexcept;
    double on_mercury() const noexcept;
    double on_venus() const noexcept;
    double on_earth() const noexcept;
    double on_mars() const noexcept;
    double on_jupiter() const noexcept;
    double on_saturn() const noexcept;
    double on_uranus() const noexcept;
    double on_neptune() const noexcept;

private:
    static constexpr double EarthYear = 31557600.0;
    long long seconds_;

    double ageOn(double orbital_period) const noexcept;
};
    
}  // namespace space_age
