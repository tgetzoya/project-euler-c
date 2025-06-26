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

Config* get_config(void) {
    return global_config;
}

void free_config(void) {
    if (global_config) {
        free((void *)global_config->base_file_path);
        free((void *)global_config->out_file_path);
        free(global_config);
        global_config = NULL;
    }
}
