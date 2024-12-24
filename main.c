#include "parser.h"
#include "grep.h"

int main(int argc, char *argv[]) {

    MyGrepOptions options;
    parse_arguments(argc, argv, &options);
    perform_grep(&options);
    





    return 0;
}