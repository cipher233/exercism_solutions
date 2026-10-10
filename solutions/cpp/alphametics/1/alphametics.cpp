#include "alphametics.h"

#include <algorithm>
#include <cctype>
#include <functional>
#include <map>
#include <numeric>
#include <optional>
#include <set>
#include <string>
#include <utility>
#include <vector>

namespace alphametics {
namespace {

std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> parts;
    std::size_t start = 0;
    while (true) {
        std::size_t pos = s.find(delim, start);
        if (pos == std::string::npos) {
            parts.push_back(s.substr(start));
            break;
        }
        parts.push_back(s.substr(start, pos - start));
        start = pos + 1;
    }
    return parts;
}

} // namespace

std::optional<std::map<char, int>> solve(const std::string& puzzle) {
    // 去掉所有空白字符
    std::string s;
    for (char c : puzzle) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            s += c;
        }
    }

    auto eq_pos = s.find("==");
    if (eq_pos == std::string::npos) {
        return std::nullopt;
    }

    std::string left = s.substr(0, eq_pos);
    std::string right = s.substr(eq_pos + 2);

    auto left_words = split(left, '+');
    auto right_words = split(right, '+');

    // coef_map[ch] 表示：左边所有加数中 ch 的位权之和 - 右边结果中 ch 的位权之和
    // 最终等式等价于 sum(coef_map[ch] * digit[ch]) == 0
    std::map<char, long long> coef_map;
    std::set<char> leading; // 不能为 0 的首字母

    auto add_word = [&](const std::string& word, int sign) {
        if (word.empty()) return;

        long long weight = 1;
        for (int i = static_cast<int>(word.size()) - 1; i >= 0; --i) {
            char ch = word[i];
            coef_map[ch] += sign * weight;
            weight *= 10;
        }

        // 多字母单词的首字母不能为 0
        if (word.size() > 1) {
            leading.insert(word[0]);
        }
    };

    for (const auto& w : left_words) {
        add_word(w, 1);
    }
    for (const auto& w : right_words) {
        add_word(w, -1);
    }

    std::vector<char> letters;
    for (const auto& kv : coef_map) {
        letters.push_back(kv.first);
    }

    int n = static_cast<int>(letters.size());
    if (n > 10) {
        return std::nullopt;
    }

    std::vector<long long> coef(n);
    std::vector<bool> is_leading(n, false);
    for (int i = 0; i < n; ++i) {
        coef[i] = coef_map[letters[i]];
        is_leading[i] = leading.count(letters[i]) > 0;
    }

    // 按系数绝对值从大到小排序，优先分配影响大的字母，便于剪枝
    std::vector<int> order(n);
    std::iota(order.begin(), order.end(), 0);

    auto absll = [](long long x) { return x < 0 ? -x : x; };
    std::sort(order.begin(), order.end(), [&](int a, int b) {
        return absll(coef[a]) > absll(coef[b]);
    });

    std::vector<char> sorted_letters(n);
    std::vector<long long> sorted_coef(n);
    std::vector<bool> sorted_leading(n);
    for (int i = 0; i < n; ++i) {
        sorted_letters[i] = letters[order[i]];
        sorted_coef[i] = coef[order[i]];
        sorted_leading[i] = is_leading[order[i]];
    }

    letters = std::move(sorted_letters);
    coef = std::move(sorted_coef);
    is_leading = std::move(sorted_leading);

    // 后缀最大/最小可能贡献，用于剪枝
    std::vector<long long> max_suffix(n + 1, 0);
    std::vector<long long> min_suffix(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        long long c = coef[i];
        if (c >= 0) {
            max_suffix[i] = max_suffix[i + 1] + c * 9;
            min_suffix[i] = min_suffix[i + 1] + c * 0;
        } else {
            max_suffix[i] = max_suffix[i + 1] + c * 0;
            min_suffix[i] = min_suffix[i + 1] + c * 9;
        }
    }

    std::vector<int> digit(n, -1);
    std::vector<bool> used(10, false);
    std::map<char, int> solution;

    std::function<bool(int, long long)> dfs = [&](int idx, long long sum) -> bool {
        if (idx == n) {
            if (sum == 0) {
                for (int i = 0; i < n; ++i) {
                    solution[letters[i]] = digit[i];
                }
                return true;
            }
            return false;
        }

        // 剪枝：即使剩余字母取最有利的值也无法使 sum 变成 0
        if (sum + max_suffix[idx] < 0 || sum + min_suffix[idx] > 0) {
            return false;
        }

        for (int d = 0; d <= 9; ++d) {
            if (used[d]) continue;
            if (d == 0 && is_leading[idx]) continue;

            used[d] = true;
            digit[idx] = d;

            if (dfs(idx + 1, sum + coef[idx] * d)) {
                return true;
            }

            used[d] = false;
            digit[idx] = -1;
        }

        return false;
    };

    if (dfs(0, 0)) {
        return solution;
    }

    return std::nullopt;
}

} // namespace alphametics