#include "problems.h"

Response* p18(void) {
    const uint_fast16_t EXPECTED = 7273;
    uint_fast16_t max_total = 0;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    uint_fast64_t num = 0;



    // char *result = filter_string_to_digits(" udsyaoifu 42 @#$@#$@#$@#$@# ");
    //
    // printf("filter_string_to_digits(\"  42  \") result: %s\n", result);
    //
    // string_to_number (result, &num);
    //
    // free(result);

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(max_total, EXPECTED, max_total == EXPECTED, start, end);
}
