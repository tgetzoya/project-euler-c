#include "problems.h"

Response* p10() {
    const uint_fast64_t EXPECTED=142913828922;

    uint_fast64_t sum = 0;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (uint_fast32_t i = 0; i < 2000000; i++) {
        if (is_prime(i)){
            sum += i;
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(sum, EXPECTED, sum == EXPECTED, start, end);
}
