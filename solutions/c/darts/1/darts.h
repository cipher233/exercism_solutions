#ifndef DARTS_H
#define DARTS_H

#include <stdint.h>

#define CENTER 10
#define INNER_CIRCLE 5
#define OUTER_CIRCLE 1
#define MISS_TARGET 0

typedef struct {
    float x;
    float y;
} coordinate_t;

uint8_t score(coordinate_t coordinate);

#endif
