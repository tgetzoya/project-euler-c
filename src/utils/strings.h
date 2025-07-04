#ifndef STRINGS_H
#define STRINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <ctype.h>

void remove_quotes(char *str);

char **split_string(const char *in, char delim, uint_fast16_t *out_count);

char *filter_string_to_digits(const char *in);

uint_fast64_t string_to_number(char *in, uint_fast64_t *out);

#endif
