#include "problems.h"

Response *p2(void) {
    const uint_fast32_t MAX = 4000000;
    const uint_fast32_t EXPECTED = 4613732;

    uint_fast32_t t1 = 1;
    uint_fast32_t t2 = 2;
    uint_fast32_t h;
    uint_fast32_t sum = 2;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    do {
        h = t1;
        t1 = t2;
        t2 += h;

        if (t2 % 2 == 0) {
            sum += t2;
        }

    } while (t2 + t1 < MAX);

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(sum, EXPECTED, sum == EXPECTED, start, end);
}
