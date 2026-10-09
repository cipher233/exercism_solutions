#pragma once

#include <array>
#include <string>

namespace kindergarten_garden {

// TODO: add your solution here
enum class Plants {
    clover,
    grass,
    violets,
    radishes,
};

std::array<Plants, 4> plants(std::string const& diagram, std::string const& student);

}  // namespace kindergarten_garden
