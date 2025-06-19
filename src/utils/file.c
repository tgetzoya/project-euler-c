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


char* read_triangle_file(const char *path) {
	// FILE *file = fopen(path, "rb");
	// if (!file) {
	// 	perror("fopen failed to open file!");
	// 	return NULL;
	// }
 //
	// char *line = NULL;
	// size_t len;
	// char *token;
	// uint_fast64_t val;
 //
	// while (getline(&line, &len, file) != -1) {
	// 	token = strtok(line, " ");
 //
	// 	while (token != NULL) {
	// 		printf("As String: %s :: ", token);
 //
	// 		if (string_to_number(token, &val) != 0) {
	// 			perror("could not parse token to number");
	// 		}
 //
	// 		printf ("As Number: %ld\n, ", val);
 //
	// 		token = strtok(NULL, " ");
	// 	}
	// }
 //
	// free(line);
	// fclose(file);

	return path;
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
