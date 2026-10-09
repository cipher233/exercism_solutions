#include "eliuds_eggs.h"

namespace chicken_coop {

// TODO: add your solution here
int positions_to_quantity(int quantity) {
    int count{0};
    while (quantity) {
        // if (quantity & 01) {
        //     ++count;
        // }
        count += (quantity & 01);
        quantity >>= 1;
    }
    return count;
}
}  // namespace chicken_coop
