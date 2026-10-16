#pragma once

#include <utility>
#include <stdexcept>

namespace queen_attack {

// TODO: add your solution here
class chess_board {
    private:
        int wr_, wc_;
        int br_, bc_;
    public:
        chess_board(const std::pair<int, int>& white, const std::pair<int, int>& black):wr_{white.first}, wc_{white.second}, br_{black.first}, bc_{black.second} {
            if (wr_ < 0 || wr_ > 7 || wc_ < 0 || wc_ > 7 ||  br_ < 0 || br_ > 7 || bc_ < 0 || bc_ > 7 || (wr_ == br_ && wc_ == bc_)) {
                throw std::domain_error("position error");
            }
                
        }

        std::pair<int, int> white() const noexcept;
        std::pair<int, int> black() const noexcept;

        bool can_attack() const;
};
    
}  // namespace queen_attack
