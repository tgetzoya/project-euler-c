#include "problems.h"

Response* p16() {
    const uint_fast16_t EXPECTED = 1366;
    uint_fast16_t sum = 0;

    mpz_t num;
    mpz_init(num);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    mpz_ui_pow_ui(num, 2, 1000);

    char *num_str = mpz_get_str(NULL, 10, num);

    for (char *p = num_str; *p; p++) {
        sum += *p - '0';
    }

    mpz_clear(num);
    free(num_str);

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(sum, EXPECTED, sum == EXPECTED, start, end);
}
