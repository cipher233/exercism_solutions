#include <array>
#include <string>
#include <vector>
#include <sstream>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // TODO: Implement round_down_scores
    std::vector<int> result;
    // result.append_range(student_scores);
    for (const auto & score : student_scores) {
        result.emplace_back(static_cast<int>(score));
    }
    return result;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // TODO: Implement count_failed_students
    int count = 0;
    for (const int &score : student_scores) {
        if (score <= 40) {
            ++count;
        }
    }
    return count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // TODO: Implement letter_grades
    int failing = 40;
    int interval = ( highest_score - 40 ) / 4;
    
    return {failing + 1, failing + interval * 1 + 1, failing + interval * 2 + 1, failing + interval * 3 + 1};
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement student_ranking
    std::vector<std::string> result;
    for (int i = 0; i < student_scores.size(); ++i) {
        // std::string rank = std::format("{}. {}: {}", i+1, student_names[i], student_scores[i])
        std::ostringstream oss;
oss << (i + 1) << ". " << student_names[i] << ": " << student_scores[i];
std::string rank = oss.str();
        result.emplace_back(rank);
    }
    return result;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    // TODO: Implement perfect_score
    for (int i = 0; i < student_scores.size(); ++i) {
        if (student_scores[i] == 100) {
            return student_names[i];
        }
    }
    return "";
}
