#include "response.h"

Response* response_init(uint_fast64_t calculated, uint_fast64_t expected, bool met, struct timespec start, struct timespec end) {
    Response *response = (Response *) malloc(sizeof(Response));

    uint_fast64_t seconds = end.tv_sec - start.tv_sec;
    int64_t nanoseconds = end.tv_nsec - start.tv_nsec;

    if (nanoseconds < 0) {
        seconds -= 1;
        nanoseconds += 1000000000L;
    }

    uint_fast64_t elapsed_ns = seconds * 1000000000ULL + nanoseconds;

    response->calculated = calculated;
    response->expected = expected;
    response->met = met;
    response->elapsed_ns = elapsed_ns;

    return response;
}


void response_free(Response *response) {
    free(response);
}

Response* static_response_fail(void) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    return response_init(0, 1, false, start, end);
}
