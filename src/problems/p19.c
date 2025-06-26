#include "problems.h"


Response *p19(void) {
    const uint_fast8_t EXPECTED = 171;
    uint_fast8_t count = 0;

    /* Creates 1901-01-01 (YYYY-MM-DD) at noon. */
    struct tm date = {0};
    date.tm_year = 1;
    date.tm_mon = 0;
    date.tm_mday = 1;
    date.tm_hour = 12;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    do {
        mktime(&date);

        if (date.tm_wday == 0) {
            ++count;
        }

        date.tm_mon += 1;
        date.tm_mday = 1;
    } while (date.tm_year < (2001 - 1900));

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(count, EXPECTED, count == EXPECTED, start, end);
}
