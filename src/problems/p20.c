#include "problems.h"


Response *p20(void) {
    const uint_fast16_t EXPECTED = 648;
    uint_fast16_t count = 0;

    mpz_t result;
    mpz_init(result);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    mpz_fac_ui(result, 100);

    char *str = mpz_get_str(NULL, 10, result);

    for (size_t idx = 0; idx < strlen(str); idx++) {
        count += str[idx] - '0';
    }

    free(str);
    mpz_clear(result);

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(count, EXPECTED, count == EXPECTED, start, end);
}
