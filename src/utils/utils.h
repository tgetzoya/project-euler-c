#ifndef UTILS_H
#define UTILS_H

#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#include "factors.h"
#include "file.h"
#include "strings.h"
#include "time.h"

uint_fast16_t count_divisors(uint_fast64_t value);

bool is_prime(uint_fast64_t value);

bool is_palindrome(char str[]);

#endif
