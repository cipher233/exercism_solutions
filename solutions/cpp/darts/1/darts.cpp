#include "darts.h"

namespace darts {

// TODO: add your solution here
int score(double x, double y) {
    double distance = x * x + y * y;
    if (distance <= 1.0) return 10;
    if (distance <= 25.0) return 5;
    if (distance <= 100.0) return 1;
    return 0;
}

}  // namespace darts
