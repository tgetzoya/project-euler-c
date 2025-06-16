#include "problems.h"

char* number_to_word (uint_fast16_t number);

Response* p17() {
    const uint_fast16_t EXPECTED = 21124;
    size_t sum = 0;
    char *number_as_word;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (uint16_t idx = 1; idx <= 1000; idx++) {
        number_as_word = number_to_word(idx);
        sum += strlen(number_as_word);
        free(number_as_word);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(sum, EXPECTED, sum == EXPECTED, start, end);
}

char* number_to_word (uint_fast16_t number) {
    static const char *singles[] = {
        "",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };

    static const char *teens[] = {
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen"
    };

    static const char *tens[] = {
        "",
        "",
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety"
    };


    char *as_word = calloc(50, sizeof(char));

    if (number == 1000) {
        strcpy(as_word, "onethousand");
    } else {
        if (number >= 100) {
            strcat(as_word, singles[number / 100]);
            strcat(as_word, "hundred");

            number %= 100;

            if (number > 0) {
                strcat(as_word, "and");
            }
        }

        if (number >= 10 && number < 20) {
            strcat(as_word, teens[number % 10]);
        } else {
            if (number >= 20) {
                strcat(as_word, tens[number / 10]);
            }

            strcat(as_word, singles[number % 10]);
        }
    }

    return as_word;
}
