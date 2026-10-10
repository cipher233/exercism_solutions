#include "high_scores.h"

#include <algorithm>
#include <queue>
#include <functional>

namespace arcade {

std::vector<int> HighScores::list_scores() const {
    // TODO: Return all scores for this session.
    return scores;
}

int HighScores::latest_score() const {
    // TODO: Return the latest score for this session.
    if (scores.empty()) {
        return {};        
    }
    return scores.back();
}

int HighScores::personal_best() const {
    // TODO: Return the highest score for this session.
    if (scores.empty()) {
        return -1;
    }
    return *std::max_element(scores.cbegin(), scores.cend());
}

std::vector<int> HighScores::top_three() const {
    // TODO: Return the top 3 scores for this session in descending order.
    std::vector<int> top3;
    if (scores.empty()) {
        return top3;
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int x : scores) {
        pq.push(x);
        if (pq.size() > 3) {
            pq.pop();
        }
    }
    while (!pq.empty()) {
        top3.push_back(pq.top());
        pq.pop();
    }
    std::reverse(top3.begin(), top3.end());
    return top3;
}

}  // namespace arcade
