#include "config.h"

static Config *global_config = NULL;

void init_config(const Config *cfg) {
    if (global_config != NULL) {
        return;
    }

    global_config = malloc(sizeof(Config));
    if (!global_config) {
        perror("Could not malloc config struct");
    }

    memcpy(global_config, cfg, sizeof(Config));
}

Config *get_config(void) {
    return global_config;
}

void free_config(void) {
    if (global_config) {

        if (global_config->base_file_path != NULL) {
            free((void *) global_config->base_file_path);
            global_config->base_file_path = NULL; // Prevent dangling pointer
        }
        if (global_config->out_file_path != NULL) {
            free((void *) global_config->out_file_path);
            global_config->out_file_path = NULL; // Prevent dangling pointer
        }

        free(global_config);
        global_config = NULL;
    }
}
