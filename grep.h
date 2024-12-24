#ifndef GREP_H
#define GREP_H

#include <stdbool.h>  
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "parser.h"
#include <ctype.h>



bool contains_keyword(const char *line, const char *keyword, bool case_insensitive);

int perform_grep(const MyGrepOptions *options);



#endif