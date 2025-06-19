#include "problems.h"

Response* p3(void) {
	const uint_fast64_t VALUE=600851475143;
	const uint_fast16_t EXPECTED=6857;

	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);

	Factors *factors = get_fast_factors(VALUE);
	uint_fast64_t largest_prime_factor = 0;

	for (uint_fast32_t i = 0; i < factors->length; i++) {
		if (is_prime(factors->factors[i]) && factors->factors[i] > largest_prime_factor) {
			largest_prime_factor = factors->factors[i];
		}
	}

	clock_gettime(CLOCK_MONOTONIC, &end);

	return response_init(largest_prime_factor, EXPECTED, largest_prime_factor == EXPECTED, start, end);
}
