#include "problems.h"

Response* p18(void) {
    const uint_fast16_t EXPECTED = 7273;
    uint_fast16_t max_total = 0;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    uint_fast64_t num = 0;

    char ** lines;
    uint16_t line_count = read_file("/home/tgetzoyan/CLionProjects/project-euler-c/files/p18.txt", &lines);

    if (lines != NULL && line_count > 0) {
        for (int idx = 0; idx < line_count; idx++) {
            printf("line: %s\n", lines[idx]);
            free(lines[idx]);
        }

        free(lines);
    } else {
        fprintf(stderr, "Failed to read file or file was empty.\n");
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(max_total, EXPECTED, max_total == EXPECTED, start, end);
}
