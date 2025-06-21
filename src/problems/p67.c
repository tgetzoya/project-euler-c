#include "problems.h"


Response* p67(void) {
    const uint_fast16_t EXPECTED = 7273;
    uint_fast16_t max_total = 0;

    char ** lines;
    char **row;

    uint_fast64_t **int_array;
    uint_fast64_t *int_row;

    int count = 0;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    uint16_t line_count = read_file("/home/tgetzoyan/CLionProjects/project-euler-c/files/p67.txt", &lines);

    int_array = calloc(line_count, sizeof(uint_fast64_t *));
    if (!int_array) {
        fprintf(stderr, "Failed to allocate memory for int_array.\n");
        return response_init(0, EXPECTED, false, start, start);
    }

    if (lines != NULL && line_count > 0) {
        for (int idx = 0; idx < line_count; idx++) {
            row = split_string(lines[idx], ' ', &count);

            int_row = calloc((idx + 1), sizeof(uint_fast64_t));

            for (int jdx = 0; jdx < idx + 1; jdx++) {
                char *filtered = filter_string_to_digits(row[jdx]);
                string_to_number(filtered, &int_row[jdx]);
                free(filtered);
                free(row[jdx]);
            }
            free(row);

            int_array[idx] = int_row;
            int_row = NULL;
            free(lines[idx]);
        }

        free(lines);
    } else {
        fprintf(stderr, "Failed to read file or file was empty.\n");
    }

    /* Work */
    for (int idx = line_count - 2; idx >= 0; idx--) {
        for (int jdx = 0; jdx < idx + 1; jdx++) {
            if (int_array[idx + 1][jdx] > int_array[idx + 1][jdx + 1]) {
                int_array[idx][jdx] += int_array[idx + 1][jdx];
            } else {
                int_array[idx][jdx] += int_array[idx + 1][jdx + 1];
            }
        }
    }
    /* End Work */

    max_total = int_array[0][0];

    /* Cleanup */
    for (int idx = 0; idx < line_count; idx++) {
        free(int_array[idx]);
    }

    puts("Freeing int_array");
    free(int_array);
    /* End Cleanup */

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(max_total, EXPECTED, max_total == EXPECTED, start, end);
}
