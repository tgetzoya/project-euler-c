#include "file.h"

uint_fast32_t create_directory(const char *path) {
#if defined(_WIN32) || defined(_WIN64)
    // Windows: _mkdir returns 0 on success, -1 on failure
    if (_mkdir(path) == 0 || errno == EEXIST) {
        return 0;
    }
    return -1;
#else
    // Unix: mkdir returns 0 on success, -1 on failure
    if (mkdir(path, 0755) == 0 || errno == EEXIST) {
        return 0;
    }
    return -1;
#endif
}

uint_fast32_t ensure_path_exists(const char *path) {
    char *path_copy = strdup(path);
    if (!path_copy) {
        perror("strdup failed");
        return -1;
    }

    size_t len = strlen(path_copy);
    if (len == 0) {
        free(path_copy);
        return 0;
    }

    // Remove trailing path separators
    while (len > 0 && (path_copy[len - 1] == '/' || path_copy[len - 1] == '\\')) {
        path_copy[len - 1] = '\0';
        len--;
    }

    for (size_t i = 1; i <= len; i++) {
        if (path_copy[i] == PATH_SEPARATOR || path_copy[i] == '\0') {
            char saved = path_copy[i];
            path_copy[i] = '\0';

            if (create_directory(path_copy) != 0) {
                // If error other than directory exists, fail
                #if defined(_WIN32) || defined(_WIN64)
                    if (GetLastError() != ERROR_ALREADY_EXISTS) {
                        perror("mkdir failed");
                        free(path_copy);
                        return -1;
                    }
                #else
                    if (errno != EEXIST) {
                        perror("mkdir failed");
                        free(path_copy);
                        return -1;
                    }
                #endif
            }
            path_copy[i] = saved;
        }
    }

    free(path_copy);
    return 0;
}


uint16_t read_file(const char *path, const char *file_name, char ***lines_out) {
    char full_path[1000];
    snprintf(full_path, sizeof(full_path), "%s/%s", path, file_name);
    
    FILE *file = fopen(full_path, "rb");
    if (!file) {
        perror("read_file could not open file");
        return 0;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    uint16_t line_count = 0;
    uint16_t capacity = 8;

    char **lines = malloc(sizeof(char*) * capacity);
    if (!lines) {
        perror("malloc failed");
        fclose(file);
        return 0;
    }

    while ((read = getline(&line, &len, file)) != -1) {
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
        }

        if (line_count >= capacity) {
            capacity *= 2;
            char **tmp = realloc(lines, sizeof(char*) * capacity);
            if (!tmp) {
                perror("realloc failed");
                break;
            }
            lines = tmp;
        }

        // Store a copy of the line
        lines[line_count] = strdup(line);
        if (!lines[line_count]) {
            perror("strdup failed");
            break;
        }

        line_count++;
    }

    free(line);
    fclose(file);

    *lines_out = lines;
    return line_count;
}

void write_json_to_file(const char *path, const char *content) {
    FILE *file = fopen(path, "wb+");
    
    if (!file) {
        perror("Failed to open file");
        return;
    }

    fputs(content, file);
    
    fclose(file);
}
