#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    bool case_insensitive;
    char *outfile;
    char *keyword;
    char **files;
    int num_files;
} MyGrepOptions;

int parse_arguments(int argc, char *argv[], MyGrepOptions *options);

#endif
