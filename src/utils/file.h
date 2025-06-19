#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #include <direct.h>  // For mkdir
    #define PATH_SEPARATOR '\\'
#else
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <unistd.h>
    #define PATH_SEPARATOR '/'
#endif

uint_fast32_t create_directory(const char *path);
uint_fast32_t ensure_path_exists(const char *path);
char* read_triangle_file(const char *path);
void write_json_to_file(const char *path, const char *content);

#endif
