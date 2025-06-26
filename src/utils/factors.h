#ifndef FACTORS_H
#define FACTORS_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint_fast64_t *factors;
    size_t length;
} Factors;

int compare_factors(const void *a, const void *b);

Factors *get_fast_factors(uint_fast64_t value);

Factors *get_factors(uint_fast64_t value, bool include_one_and_value, bool do_sort);

void free_factor(Factors *);

#endif
