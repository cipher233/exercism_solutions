#include "kindergarten_garden.h"

#include <sstream>
#include <algorithm>
#include <iterator>

namespace kindergarten_garden {
namespace {

Plants to_plant(char code) {
    switch (code) {
        case 'C': return Plants::clover;
        case 'G': return Plants::grass;
        case 'V': return Plants::violets;
        case 'R': return Plants::radishes;
    }
    return Plants::clover;
}

const std::array<std::string, 12> students{
    "Alice", "Bob", "Charlie", "David", "Eve", "Fred",
    "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"
};

}  // namespace

// TODO: add your solution here
std::array<Plants, 4> plants(std::string const& diagram, std::string const& student) {
    auto const it = std::find(students.begin(), students.end(), student);
    if (it == students.end()) {
        throw std::invalid_argument("Unknown student");
    }
    auto const student_index = static_cast<std::size_t>(std::distance(students.begin(), it));
    auto const left = student_index * 2;
    
    std::istringstream input(diagram);
    std::string top_row;
    std::string bottom_row;

    if (!std::getline(input, top_row) ||
        !std::getline(input, bottom_row) ||
        top_row.size() < left + 2 ||
        bottom_row.size() < left + 2) {
        throw std::invalid_argument("Invalid garden diagram");
    }
    
    return {
        to_plant(top_row[left]),
        to_plant(top_row[left + 1]),
        to_plant(bottom_row[left]),
        to_plant(bottom_row[left + 1]),
    };
}
    
}  // namespace kindergarten_garden
