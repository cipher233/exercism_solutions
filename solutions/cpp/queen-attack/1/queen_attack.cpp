#include "queen_attack.h"

namespace queen_attack {

// TODO: add your solution here
std::pair<int, int> chess_board::white() const noexcept {
    return {wr_, wc_};
}

std::pair<int, int> chess_board::black() const noexcept {
    return {br_, bc_};
}

bool chess_board::can_attack() const {
    int r_diff = br_ - wr_;
    int c_diff = bc_ - wc_;
    if (r_diff <0 ) {
        r_diff = -r_diff;
    }
    if (c_diff < 0) {
        c_diff = -c_diff;
    }
    if (wr_ == br_ || wc_ == bc_ || r_diff == c_diff) {
        return true;
    }
    return false;
}
}  // namespace queen_attack
