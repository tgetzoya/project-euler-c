#include "problems.h"

Response* p9(void) {
    const int EXPECTED=31875000;
    uint_fast32_t product = 0, c = 0;
    bool found = false;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (uint_fast16_t a = 1; a < (1000 / 3) && !found; a++) {
        for (uint_fast16_t b = a + 1; b < (1000 / 2) && !found; b++) {
            c = 1000 - a - b;

            if ((a * a) + (b * b) == (c *c )) {
                product = a * b * c;
                found = true;
            }
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(product, EXPECTED, product == EXPECTED, start, end);
}
