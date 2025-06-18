#include "time.h"

char* ns_to_readable (uint_fast64_t nanoseconds) {
    if (nanoseconds < NS_TO_µs) {
        return format_ns(NANOSECOND_ID, nanoseconds);
    } else if (nanoseconds < NS_TO_MS) {
        return format_ns(MICROSECOND_ID, (float) (nanoseconds / (float) NS_TO_µs));
    } else if (nanoseconds < NS_TO_S) {
        return format_ns(MILLISECOND_ID, (float) nanoseconds / (float) NS_TO_MS);
    } else if (nanoseconds < NS_TO_MIN) {
        return format_ns(SECOND_ID, (float) nanoseconds/ (float) NS_TO_S);
    }

    return format_ns(MINUTE_ID, (float) nanoseconds / (float) NS_TO_MIN);
}

char* format_ns(const char *id, float elapsed) {
    size_t size = snprintf(NULL, 0, "%.3f %s", elapsed, id);
    if (size < 0) {
        return NULL;
    }

    char* buffer = malloc(size + 1);
    if (buffer == NULL) {
        return NULL;
    }

    snprintf(buffer, size + 1, "%.3f %s\n", elapsed, id);
    return buffer;
}
