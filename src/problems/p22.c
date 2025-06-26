#include "problems.h"

int cmp_str(const void *a, const void *b) {
    const char *const *pa = a;
    const char *const *pb = b;
    return strcmp(*pa, *pb);
}

Response *p22(void) {
    const uint_fast32_t EXPECTED = 871198282;
    uint_fast32_t total = 0;

    char **lines;

    Config *config = get_config();

    if (config->base_file_path == NULL) {
        perror("No base file path given");
        return static_response_fail();
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    uint16_t line_count = read_file(config->base_file_path, "p22.txt", &lines);

    /* File is one line long, no need for an array; */
    if (lines && line_count > 0) {
        uint_fast16_t name_count;
        char **names = split_string(lines[0], ',', &name_count);

        for (uint_fast16_t idx = 0; idx < name_count; idx++) {
            remove_quotes(names[idx]);
        }

        qsort(names, name_count, sizeof(char *), cmp_str);

        uint_fast32_t int_val;
        size_t str_len;
        for (uint_fast16_t idx = 0; idx < name_count; idx++) {
            int_val = 0;
            str_len = strlen(names[idx]);
            for (uint_fast16_t jdx = 0; jdx < str_len; jdx++) {
                int_val += (names[idx][jdx] - 'A') + 1;
            }

            total += int_val * (idx + 1);

            free(names[idx]);
        }

        free(names);
        free(lines[0]);
        free(lines);
    } else {
        fprintf(stderr, "Failed to read file or file was empty.\n");
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    return response_init(total, EXPECTED, total == EXPECTED, start, end);
}
