#include "factors.h"

int compare_factors(const void *a, const void *b) {
    uint_fast64_t arg1 = *(const uint_fast64_t *) a;
    uint_fast64_t arg2 = *(const uint_fast64_t *) b;
    return (arg1 > arg2) - (arg1 < arg2);
}

Factors *get_fast_factors(uint_fast64_t value) {
    return get_factors(value, false, false);
}

Factors *get_factors(uint_fast64_t value, bool include_one_and_value, bool do_sort) {
    const size_t size_of_variable = sizeof(uint_fast64_t);

    size_t capacity = 10;
    size_t element_count = 0;

    Factors *result;
    uint_fast64_t *factors = calloc(capacity, size_of_variable);
    uint_fast64_t *tmp;

    if (factors == NULL) {
        return NULL;
    }

    if (include_one_and_value) {
        factors[element_count++] = 1;
        if (value != 1) {
            factors[element_count++] = value;
        }
    }

    if (value >= 2) {
        for (uint_fast64_t i = 2; i <= value / i; i++) {
            if (value % i == 0) {
                if (capacity - element_count <= 2) {
                    capacity *= 2;


                    tmp = realloc(factors, capacity * size_of_variable);

                    if (tmp == NULL) {
                        free(factors);
                        return NULL;
                    }

                    factors = tmp;
                }

                if (i == value / i) {
                    factors[element_count++] = i;
                } else {
                    factors[element_count++] = i;
                    factors[element_count++] = value / i;
                }
            }
        }

        if (do_sort && element_count > 1) {
            qsort(factors, element_count, sizeof(uint_fast64_t), compare_factors);
        }
    }


    tmp = realloc(factors, element_count * size_of_variable);

    if (tmp == NULL) {
        free(factors);
        return NULL;
    }

    factors = tmp;

    result = malloc(sizeof(Factors));

    if (result == NULL) {
        free(factors);
        return NULL;
    }

    result->factors = factors;
    result->length = element_count;

    return result;
}

void free_factor(Factors *factors) {
    free(factors->factors);
    free(factors);
}
