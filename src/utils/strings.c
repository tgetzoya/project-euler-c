#include "strings.h"

void remove_quotes(char *str) {
    char *read = str;
    char *write = str;

    while (*read) {
        if (*read != '"' && *read != '\'') {
            *write++ = *read;
        }
        read++;
    }
    *write = '\0';
}

char **split_string(const char *in, char delim, uint_fast16_t *out_count) {
    if (!in || !out_count) {
        return NULL;
    }

    char *str = strdup(in);
    if (!str) {
        return NULL;
    }

    size_t capacity = 8;
    size_t count = 0;
    char **tokens = malloc(sizeof(char *) * capacity);
    if (!tokens) {
        free(str);
        return NULL;
    }

    char delim_str[2] = {delim, '\0'};
    char *token = strtok(str, delim_str);

    while (token != NULL) {
        if (count == capacity) {
            capacity *= 2;
            char **new_tokens = realloc(tokens, sizeof(char *) * capacity);
            if (!new_tokens) {
                for (size_t i = 0; i < count; i++) free(tokens[i]);
                free(tokens);
                free(str);
                return NULL;
            }
            tokens = new_tokens;
        }

        tokens[count] = strdup(token);
        if (!tokens[count]) {
            for (size_t i = 0; i < count; i++) free(tokens[i]);
            free(tokens);
            free(str);
            return NULL;
        }

        count++;
        token = strtok(NULL, delim_str);
    }

    free(str);
    *out_count = (uint_fast16_t)count;
    return tokens;
}


char *filter_string_to_digits(const char *in) {
    size_t count = 0;

    for (const char *ch = in; *ch; ch++) {
        if (isdigit((unsigned char) *ch)) {
            count++;
        }
    }

    char *out = malloc(sizeof(char) * (count + 1));
    if (!out) {
        perror("filter_string_to_digits malloc failed");
        return NULL;
    }

    char *copy = out;
    for (const char *ch = in; *ch; ch++) {
        if (isdigit((unsigned char) *ch)) {
            *copy++ = *ch;
        }
    }

    *copy = '\0';

    return out;
}

uint_fast64_t string_to_number(char *in, uint_fast64_t *out) {
    if (in == NULL || out == NULL) return 255;

    errno = 0;
    char *endptr;
    long val = strtol(in, &endptr, 10);

    if (errno == ERANGE) {
        perror("string_to_number strtol failed");
        return 1;
    }

    if (endptr == in || *endptr != '\0') {
        fprintf(stderr, "Invalid integer: %s\n", in);
        return 2;
    }

    *out = (uint_fast64_t) val;

    return 0;
}
