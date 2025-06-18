#include "file.h"

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
