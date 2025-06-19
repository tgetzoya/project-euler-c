#include "problems.h"

Response* p1(void) {
	const uint_fast32_t MAX = 1000;
	const uint_fast32_t EXPECTED = 233168;

	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);

	uint_fast32_t sum = 0;

	for (uint_fast32_t i = 1; i < MAX; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}

	clock_gettime(CLOCK_MONOTONIC, &end);

	return response_init(sum, EXPECTED, sum == EXPECTED, start, end);
}
