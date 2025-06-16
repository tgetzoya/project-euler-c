#include "utils.h"

const uint_fast64_t NS_TO_µs  = 1000;
const uint_fast64_t NS_TO_MS  = 1000000;
const uint_fast64_t NS_TO_S   = 1000000000;
const uint_fast64_t NS_TO_MIN = 60000000000;

const char *NANOSECOND_ID = "ns (fastest)";
const char *MICROSECOND_ID = "µs (second fastest)";
const char *MILLISECOND_ID = "ms (median)";
const char *SECOND_ID = "s (slow)";
const char *MINUTE_ID = "min (not acceptable)";

bool is_prime (uint_fast64_t value){
	if (value < 2) {
		return false;
	}

	if (value <= 3) {
		return value > 1;
	}

	if (value % 2 == 0 || value % 3 == 0) {
		return false;
	}

	for (uint_fast64_t i = 5; i <= value / i; i += 6) {
		if (value % i == 0 || value % (i + 2) == 0) {
			return false;
		}
	}

	return true;
}

uint_fast16_t count_divisors (uint_fast64_t value) {
	uint_fast16_t count = 0;
	uint_fast32_t root = (uint_fast32_t) sqrt(value);

	for (uint_fast32_t i = 1; i <= value / i; i++) {
		if (value % i == 0) {
			count += 2;
		}
	}

	if (root * root == value) {
		count--;
	}

	return count;
}

int compare_factors (const void *a, const void *b) {
	uint_fast64_t arg1 = *(const uint_fast64_t *)a;
	uint_fast64_t arg2 = *(const uint_fast64_t *)b;
	return (arg1 > arg2) - (arg1 < arg2);
}

Factors* get_fast_factors (uint_fast64_t value){
	return get_factors(value, false, false);
}

Factors* get_factors (uint_fast64_t value, bool include_one_and_value, bool do_sort) {
	const size_t size_of_variable = sizeof(uint_fast64_t);

	size_t capacity = 10;
	size_t element_count = 0;

	Factors *result;
	uint_fast64_t *factors = calloc(capacity,  size_of_variable);
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

bool is_palindrome(char str[]) {
	int end = strlen(str) - 1;
	int start = 0;

	if (end <= 0) {
		return false;
	}

	do {
		if (str[start] != str[end]) {
			return false;
		}

		++start;
		--end;
	} while (end > start);

	return true;
}

char* ns_to_readable (uint_fast64_t nanoseconds) {
	if (nanoseconds < NS_TO_µs) {
		return format_ns(NANOSECOND_ID, nanoseconds);
	} else if (nanoseconds < NS_TO_MS) {
		return format_ns(MICROSECOND_ID, (float) (nanoseconds / (float) NS_TO_µs));
	} else if (nanoseconds < NS_TO_S) {
		return format_ns(MILLISECOND_ID, (float) nanoseconds / (float) NS_TO_MS);
	} else if (nanoseconds < NS_TO_MIN) {
		return format_ns(SECOND_ID, (float) nanoseconds/ (float) NS_TO_S);
	}

	return format_ns(MINUTE_ID, (float) nanoseconds / (float) NS_TO_MIN);
}

char* format_ns(const char *id, float elapsed) {
	int size = snprintf(NULL, 0, "%.3f %s", elapsed, id);
	if (size < 0) {
		return NULL;
	}

	char* buffer = malloc(size + 1);
	if (buffer == NULL) {
		return NULL;
	}

	snprintf(buffer, size + 1, "%.3f %s\n", elapsed, id);
	return buffer;
}
