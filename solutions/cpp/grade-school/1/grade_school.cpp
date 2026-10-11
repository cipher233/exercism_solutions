#include "grade_school.h"

#include <algorithm>

namespace grade_school {

// TODO: add your solution here

[[nodiscard]] std::map<int, std::vector<std::string>> school::roster() const {           return roster_;
}

void school::add(const std::string& name, const int grade) {
    if (exist(name)) {
        return;
    }

    auto& students = roster_[grade];

    auto it = std::lower_bound(
        students.begin(), students.end(), name
    );

    students.insert(it, name);
}



[[nodiscard]] std::vector<std::string> school::grade(const int grade) const {
    auto it = roster_.find(grade);

    if (it == roster_.end()) {
        return {};
    }

    return it->second;
}

[[nodiscard]] bool school::exist(const std::string& name) const {
    for (const auto& [current_grade, students] : roster_) {
        if (std::find(students.begin(), students.end(), name)
            != students.end()) {
            return true;
        }
    }

    return false;
}

}  // namespace grade_school
