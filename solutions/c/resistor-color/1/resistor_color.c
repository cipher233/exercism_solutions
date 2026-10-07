#include "resistor_color.h"

int color_code(resistor_band_t band) {
    return band;
}

resistor_band_t const* colors() {
    static resistor_band_t all_colors[] = {BLACK, BROWN, RED,       ORANGE, YELLOW,GREEN, BLUE,  VIOLET, GREY,   WHITE };
    return all_colors;
}