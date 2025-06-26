#include "problems.h"

Response *p5(void) {
    const uint_fast32_t EXPECTED = 232792560;
    uint_fast32_t value = 0;
    bool all_divisible;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (uint_fast32_t idx = 20; idx < INT_MAX; idx += 20) {
        all_divisible = true;

        for (uint_fast8_t jdx = 19; jdx > 1; jdx--) {
            if (idx % jdx != 0) {
                all_divisible = false;
                break;
            }
        }

        if (all_divisible) {
            value = idx;
            break;
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(value, EXPECTED, value == EXPECTED, start, end);
}
