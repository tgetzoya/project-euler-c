#include "problems.h"

uint_fast32_t sum_of_squares(uint_fast32_t sequence_length);

uint_fast32_t square_of_sum(uint_fast32_t sequence_length);

Response *p6(void) {
    const uint_fast32_t EXPECTED = 25164150;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    uint_fast32_t one = sum_of_squares(100);
    uint_fast32_t two = square_of_sum(100);
    uint_fast32_t value = one > two ? one - two : two - one;

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(value, EXPECTED, value == EXPECTED, start, end);
}

uint_fast32_t sum_of_squares(uint_fast32_t sequence_length) {
    uint_fast32_t sum = 0;

    for (uint_fast32_t i = 1; i <= sequence_length; i++) {
        sum += (i * i);
    }

    return sum;
}


uint_fast32_t square_of_sum(uint_fast32_t sequence_length) {
    uint_fast32_t sum = 0;

    for (uint_fast32_t i = 1; i <= sequence_length; i++) {
        sum += i;
    }

    return sum * sum;;
}
