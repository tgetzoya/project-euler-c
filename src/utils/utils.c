#include "utils.h"

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

bool is_palindrome(char str[]) {
	size_t end = strlen(str) - 1;
	uint_fast16_t start = 0;

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


