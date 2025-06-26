#ifndef TIME_H
#define TIME_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

static const uint_fast64_t NS_TO_µs = 1000;
static const uint_fast64_t NS_TO_MS = 1000000;
static const uint_fast64_t NS_TO_S = 1000000000;
static const uint_fast64_t NS_TO_MIN = 60000000000;

static const char *NANOSECOND_ID = "ns (fastest)";
static const char *MICROSECOND_ID = "µs (second fastest)";
static const char *MILLISECOND_ID = "ms (median)";
static const char *SECOND_ID = "s (slow)";
static const char *MINUTE_ID = "min (not acceptable)";

char *ns_to_readable(uint_fast64_t nanoseconds);

char *format_ns(const char *fmt, float elapsed);

#endif
