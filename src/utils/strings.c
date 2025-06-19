#include "strings.h"

char* filter_string_to_digits (const char *in) {
    size_t count = 0;

    for (const char *ch = in; *ch; ch++) {
        if (isdigit((unsigned char)*ch)) {
            count++;
        }
    }

    char *out = malloc(sizeof(char) * (count + 1));
    if (!out) {
        perror("filter_string_to_digits malloc failed");
        return NULL;
    }

    char *copy = out;
    for (const char *ch = in; *ch; ch++) {
        if (isdigit((unsigned char)*ch)) {
            *copy++ = *ch;
        }
    }

    *copy = '\0';

    printf("Returning %s\n", out);

    return out;
}

uint_fast64_t string_to_number(char* in, uint_fast64_t* out) {
    if (in == NULL || out == NULL) return 255;

    errno = 0;
    char *endptr;
    long val = strtol(in, &endptr, 10);

    if (errno == ERANGE) {
        perror("string_to_number strtol failed");
        return 1;
    }

    if (endptr == in || *endptr != '\0') {
        fprintf(stderr, "Invalid integer: %s\n", in);
        return 2;
    }

    *out = (uint_fast64_t)val;

    return 0;
}
