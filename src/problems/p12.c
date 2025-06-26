#include "problems.h"

Response *p12(void) {
    const uint_fast16_t MIN_DIVISORS = 500;
    const uint_fast32_t EXPECTED = 76576500;

    uint_fast64_t number = 0;
    uint_fast16_t divisor_count = 0;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (uint_fast16_t idx = 1; divisor_count <= MIN_DIVISORS; idx++) {
        number += idx;

        divisor_count = count_divisors(number);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(number, EXPECTED, number == EXPECTED, start, end);
}
