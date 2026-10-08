#include "queen_attack.h"


attack_status_t can_attack(position_t queen_1, position_t queen_2) {
    int q1r = queen_1.row;
    int q1c = queen_1.column;
    int q2r = queen_2.row;
    int q2c = queen_2.column;
    if (q1r < 0 || q1r > 7 || q1c < 0 || q1c > 7 || q2r < 0 || q2r > 7 || q2c < 0 || q2c > 7) {
        return INVALID_POSITION;
    }
    if (q1r == q2r && q1c == q2c) {
        return INVALID_POSITION;
    }
    int row_diff = q2r - q1r;
    int col_diff = q2c - q1c;
    if (row_diff < 0) { row_diff = -row_diff; }
    if (col_diff < 0) { col_diff = -col_diff; }
    if (q1r == q2r || q1c == q2c || row_diff == col_diff) {
        return CAN_ATTACK;
    }

    return CAN_NOT_ATTACK;
}