#pragma once

#include <map>
#include <vector>
#include <string>

namespace grade_school {

// TODO: add your solution here
class school {
public:
    [[nodiscard]]
    std::map<int, std::vector<std::string>> roster() const;

    void add(const std::string& name, const int grade);

    [[nodiscard]]
    std::vector<std::string> grade(int grade) const;

private:
    std::map<int, std::vector<std::string>> roster_;

    [[nodiscard]]
    bool exist(const std::string& name) const;
};

}  // namespace grade_school
