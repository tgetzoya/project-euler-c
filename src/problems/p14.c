#include "problems.h"

Response* p14(void) {
    const uint_fast32_t EXPECTED=837799;

    uint_fast32_t longest_chain_idx = 0;
    uint_fast32_t length = 0;
    uint_fast32_t max_length = 0;
    uint_fast64_t value;
    uint_fast32_t cache[1000000] = {0};
    cache[1] = 1;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (uint_fast32_t idx = 1; idx < 1000000; idx++) {
        value = idx;
        length = 0;

        do {
            if (value < 1000000 && cache[value] > 0) {
                length += cache[value];
                break;
            }


            ++length;

            if (value % 2 == 0) {
                value /= 2;
            } else {
                value = (3 * value) + 1;
            }
        } while (value != 1);

        cache[idx] = length;


        if (length > max_length) {
            longest_chain_idx = idx;
            max_length = length;
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(longest_chain_idx, EXPECTED, longest_chain_idx == EXPECTED, start, end);
}
