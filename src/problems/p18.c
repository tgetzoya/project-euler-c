#include "problems.h"

Response* p18(void) {
    const uint_fast16_t EXPECTED = 7273;
    uint_fast16_t max_total = 0;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // read_triangle_file("./files/p18.txt");

    uint_fast64_t num = 0;

    string_to_number ("  42  ", &num);

    printf("Number is: %llu\n", num);

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(max_total, EXPECTED, max_total == EXPECTED, start, end);
}
