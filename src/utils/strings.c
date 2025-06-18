#include "strings.h"

uint_fast64_t string_to_number(char* in, uint_fast64_t* out) {
    if (in == NULL || out == NULL) return 255;

    errno = 0;
    char *endptr;
    long val = strtol(in, &endptr, 10);

    if (errno == ERANGE || val < 0 || val > INT_MAX) {
        return 1;
    }
    if (endptr == in || *endptr != '\0') {
        return 2;
    }

    *out = (uint_fast64_t)val;
    return 0;
}
