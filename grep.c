#include "grep.h"

bool contains_keyword(const char *line, const char *keyword, bool case_insensitive) {

    if (case_insensitive) {
        char *lower_line = strdup(line); 
        char *lower_keyword = strdup(keyword);


        for(char *p = lower_line; *p; p++) {
            *p = tolower(*p);
        }
        for (char *p = lower_keyword; *p; p++) {
            *p = tolower(*p);
        }

        bool found = strstr(lower_line, lower_keyword) != NULL;
        free(lower_line);
        free(lower_keyword);
        return found;
    } else {
        return strstr(line, keyword) != NULL;
    }
}

int perform_grep(const MyGrepOptions *options) {
    FILE *output = stdout;
    if (options->outfile) {
        output = fopen(options->outfile, "w");
        if (!output) {
            perror("Error opening file:");
            exit(1);
        }
    }

    FILE *input = NULL;
    char line[1024];

    if (options->files == 0) {
        input = stdin;
        while (fgets(line, sizeof(line),stdin)) {
            if (contains_keyword(line, options->keyword, options->case_insensitive)) {
                fprintf(output, "%s", line);
            }
        }
    } else {
        for (int i = 0; i < options->num_files; i++) {
            input = fopen(options->files[i], "r");
            if (!input) {
                perror("Error reading input File");
                exit(1);
            } else {
                while (fgets(line, sizeof(line), input)) {
                    if (contains_keyword(line, options->keyword, options->case_insensitive)) {
                        fprintf(output, "%s", line);
                    }
                }
            }
        }
    }
}