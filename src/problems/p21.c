#include "problems.h"

uint_fast32_t sum_divisors(Factors* factors) {
    uint_fast32_t sum = 1; /* For this, 1 is evenly divisible. The number itself is not a factor.*/
    
    for (uint8_t idx = 0; idx < factors->length; idx++) {
        sum += factors->factors[idx];
    }
    
    return sum;
}

Response* p21(void) {
    const uint_fast32_t EXPECTED = 31626;
    uint_fast32_t sum = 0;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    for (uint_fast16_t idx = 0; idx < 10000; idx++) {
        Factors* factors_of_idx = get_fast_factors (idx);
        uint_fast32_t jdx = sum_divisors(factors_of_idx);
        
        Factors* factors_of_jdx = get_fast_factors (jdx);
        uint_fast32_t sum_of_jdx = sum_divisors(factors_of_jdx);
        
        if (idx != jdx && sum_of_jdx == idx) {
            sum += idx ;
        }
        
        free_factor(factors_of_idx);
        free_factor(factors_of_jdx);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(sum, EXPECTED, sum == EXPECTED, start, end);
}
