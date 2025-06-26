#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint_fast16_t specific_problem;
    const char *base_file_path;
    const char *out_file_path;
    bool write_to_file;
} Config;

Config *get_config(void);

void init_config(const Config *cfg);

void free_config(void);

#endif // CONFIG_H
