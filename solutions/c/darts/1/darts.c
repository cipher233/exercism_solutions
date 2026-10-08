#include "darts.h"
#include <math.h>


uint8_t score(coordinate_t const coordinate) {
    float x = coordinate.x;
    float y = coordinate.y;

    float distance = sqrtf(x * x + y * y);
    if(distance <= 1.0f) {
        return CENTER;
    }else if(distance <= 5.0f) {
        return INNER_CIRCLE;
    }else if(distance <= 10.0f) {
        return OUTER_CIRCLE;
    }else {
        return MISS_TARGET;
    }
}