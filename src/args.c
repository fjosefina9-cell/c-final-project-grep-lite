
#include <string.h>
#include "args.h"

int parse_args(int argc, char *argv[], struct Args *args) {
    args->ignore_case = 0;
    args->whole_word = 0;
    args->line_numbers = 0;
    args->count_only = 0;
    args->pattern = NULL;
    args->file_count = 0;

    int i = 1;

    // Handle flags
    while (i < argc && argv[i][0] == '-') {
        if (strcmp(argv[i], "-i") == 0) {
            args->ignore_case = 1;
        } else if (strcmp(argv[i], "-w") == 0) {
            args->whole_word = 1;
        } else if (strcmp(argv[i], "-n") == 0){
            args->line_numbers = 1;
        } else if (strcmp(argv[i], "-c") == 0){
            args->count_only =1;
        } else { 
            return 1;
        }
        i++;
    }

    // Now pattern and filename
    if (i >= argc) return 1;
    args->pattern = argv[i++];

    while(i < argc && args->file_count < MAX_FILES) {
        args->files[args->file_count] = argv[i];
        args->file_count++;
        i++;
    }

    return 0;
}
