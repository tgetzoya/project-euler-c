#include "problems.h"

Response* p4(void) {
	const uint_fast32_t EXPECTED=906609;
	char num_as_string[10];
	uint_fast32_t largest = 0;

	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);

	for (uint_fast16_t idx = 999; idx > 99; idx--) {
		for (uint_fast16_t jdx = 999; jdx > 99; jdx--) {
			uint_fast32_t value = idx * jdx;
			sprintf(num_as_string, "%d", value);

			if (is_palindrome(num_as_string) && value > largest) {
				largest = value;
			}
		}
	}

	clock_gettime(CLOCK_MONOTONIC, &end);

	return response_init(largest, EXPECTED, largest == EXPECTED, start, end);
}

