#include "parser.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>



void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s [-i] [-o outfile] keyword [file...]\n", prog_name);
}


int parse_arguments(int argc, char *argv[], MyGrepOptions *options) {
    int opt;
    options->case_insensitive = false;
    options->outfile = NULL;
    options->keyword = NULL;
    options->files = NULL;
    options->num_files = 0;
    


   while ( (opt = getopt(argc, argv, "io:")) != -1) {

        switch(opt) {

           case 'i':
               options->case_insensitive = true;
               break;
       
           case 'o':
               options->outfile = strdup(optarg);
               break;
 
           case '?':
              print_usage(argv[0]);
              exit(1);
        }
   }

   if (optind < argc) {
        options->keyword = argv[optind++];
        printf("keyword: %s\n", options->keyword);
   } else {
        print_usage(argv[0]);
        exit(1);
   }


   if (optind < argc) {
        options->num_files = argc - optind;
        options->files = &argv[optind];
   }



}
