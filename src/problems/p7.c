#include "problems.h"

Response* p7(void) {
    const uint_fast16_t NUMBER_OF_PRIMES = 10001;
    const uint_fast32_t EXPECTED=104743;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    uint_fast32_t prime_count = 0;
    uint_fast64_t value = 1;

    do {
        ++value;

        if (is_prime(value)) {
            ++prime_count;
        }
    } while (prime_count < NUMBER_OF_PRIMES);

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(value, EXPECTED, value == EXPECTED, start, end);
}
