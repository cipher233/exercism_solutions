#include "difference_of_squares.h"


unsigned int sum_of_squares(unsigned int number) {
    unsigned int ans = 0;
    for (unsigned int i = 1; i <= number; ++i){
        ans += i * i;
    }
    return ans;
}
unsigned int square_of_sum(unsigned int number) {
    unsigned int ans = 0;
    for (unsigned int i = 1; i <= number; ++i){
        ans += i;
    }
    return ans * ans;
}
unsigned int difference_of_squares(unsigned int number){
    return square_of_sum(number) - sum_of_squares(number);
}