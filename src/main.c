#include "includes.h"

int main (int argc, char **argv) {
    int opt;
    uint_fast16_t specific_problem = 0;
    while ((opt = getopt(argc, argv, "p:")) != -1) {
        switch (opt) {
            case 'p':
                specific_problem = strtol(optarg, NULL, 10);
                puts("WE GOT P");
                break;
            case '?':
                // getopt prints an error message for unknown options.
                printf("Unknown option: -%c\n", optopt);
                break;
        }
    }


    Response *response;

    size_t available_problems = sizeof(p_list) / sizeof(p_list[0]);

    if (specific_problem > available_problems) {
        specific_problem = 0;
    }

    for (size_t i = (specific_problem > 0 ? specific_problem - 1 : 0); i < (specific_problem > 0 ? specific_problem : available_problems); i++) {
        response = p_list[i]();

        char *readable_elapsed = ns_to_readable(response->elapsed_ns);
        printf("Problem %3zu\n\tTotal:    %lu\n\tExpected: %lu\n\tMet:      %s\n\tElapsed:  %s\n",
            i + 1,
            response->calculated,
            response->expected,
            response->met ? "\033[32mYES\033[0m" : "\033[31mNO\033[0m",
            readable_elapsed
        );

        free(readable_elapsed);
        response_free(response);
    }

    return 0;
}
