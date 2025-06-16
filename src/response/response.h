#ifndef __RESPONSE_H__
#define __RESPONSE_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    uint_fast64_t calculated;
    uint_fast64_t expected;
    bool met;
    uint_fast64_t elapsed_ns;
} Response;

Response* response_init(uint_fast64_t calculated, uint_fast64_t expected, bool met, struct timespec start, struct timespec end);
void response_free(Response *response);

#endif // __RESPONSE_H__
