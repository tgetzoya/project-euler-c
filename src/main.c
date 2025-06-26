#include "includes.h"

int main (int argc, char **argv) {
    int opt;
    
    Config config;

    while ((opt = getopt(argc, argv, "f:p:o:")) != -1) {
        switch (opt) {
            case 'f':
                config.base_file_path = strdup(optarg);
                break;
            case 'p':
                config.specific_problem = strtol(optarg, NULL, 10);
                break;
            case 'o':
                config.out_file_path = strdup(optarg);
                config.write_to_file = true;
                break;
            case '?':
                // getopt prints an error message for unknown options.
                printf("Unknown option: -%c\n", optopt);
                break;
        }
    }
    
    init_config(&config);

    size_t available_problems = sizeof(p_list) / sizeof(p_list[0]);
    
    Response **responses = NULL;
    Response *response;
    size_t response_count = 0;

    if (config.specific_problem > available_problems) {
        config.specific_problem = 0;
    }
    
    if (config.write_to_file) {
        if (config.specific_problem > 0) {
            /* Exactly 1 */
            responses = malloc(sizeof(Response *));
        } else {
            responses = malloc(available_problems * sizeof(Response *));
        }
    }

    for (size_t i = (config.specific_problem > 0 ? config.specific_problem - 1 : 0); i < (config.specific_problem > 0 ? config.specific_problem : available_problems); i++) {
        response = p_list[i]();

        char *readable_elapsed = ns_to_readable(response->elapsed_ns);
        printf("Problem %3zu\n\tTotal:    %llu\n\tExpected: %llu\n\tMet:      %s\n\tElapsed:  %s\n",
            i + 1,
            response->calculated,
            response->expected,
            response->met ? "\033[32mYES\033[0m" : "\033[31mNO\033[0m",
            readable_elapsed
        );

        free(readable_elapsed);
        
        if (config.write_to_file) {
            responses[response_count++] = response;
        } else {
            response_free(response);
        }
    }

    if (config.write_to_file && config.out_file_path != NULL) {
        cJSON *json_array = cJSON_CreateArray();

        for (size_t idx = 0; idx < response_count; idx++) {
            if (responses[idx] == NULL) continue;

            cJSON *json_obj = cJSON_CreateObject();

            char *readable_elapsed = ns_to_readable(responses[idx]->elapsed_ns);

            cJSON_AddNumberToObject(json_obj, "problem_id", idx+1);
            cJSON_AddNumberToObject(json_obj, "calculated", responses[idx]->calculated);
            cJSON_AddNumberToObject(json_obj, "expected", responses[idx]->expected);
            cJSON_AddStringToObject(json_obj, "met", responses[idx]->met ? "YES" : "NO");
            cJSON_AddStringToObject(json_obj, "elapsed", readable_elapsed);

            cJSON_AddItemToArray(json_array, json_obj);

            free(readable_elapsed);
            /* Destroy the individual objects. */
            response_free(responses[idx]);
        }

        /* Then destroy the array. */
        free(responses);

        char *json_str = cJSON_Print(json_array);

        time_t now = time(NULL);

        char file_name[1000];
        snprintf(file_name, sizeof(file_name), "%s/%s-%ld.json", config.out_file_path, OS, now);

        if (ensure_path_exists(config.out_file_path) == 0) {
            printf("Directory path exists or was created successfully.\n");
        } else {
            fprintf(stderr, "Failed to create directory path.\n");
        }

        write_json_to_file(file_name, json_str);

        cJSON_Delete(json_array);
    }
    
    free_config();
    return 0;
}
