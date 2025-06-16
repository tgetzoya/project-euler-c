#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

typedef struct {
    uint_fast64_t *factors;
    size_t length;
} Factors;

bool is_prime (uint_fast64_t value);

uint_fast16_t count_divisors (uint_fast64_t value);
int compare_factors (const void *a, const void *b);
Factors* get_fast_factors (uint_fast64_t value);
Factors* get_factors (uint_fast64_t value, bool include_one_and_value, bool do_sort);
void free_factor(Factors *);

bool is_palindrome(char str[]);

char* ns_to_readable (uint_fast64_t nanoseconds);
char* format_ns(const char *fmt, float elapsed);

#endif
