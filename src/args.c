
#include <string.h>
#include "args.h"

int parse_args(int argc, char *argv[], struct Args *args) {
    args->ignore_case = 0;
    args->whole_word = 0;

    int i = 1;

    // Handle flags
    while (i < argc && argv[i][0] == '-') {
        if (strcmp(argv[i], "-i") == 0) {
            args->ignore_case = 1;
        } else if (strcmp(argv[i], "-w") == 0) {
            args->whole_word = 1;
        }
        i++;
    }

    // Now pattern and filename
    if (i >= argc) return 1;
    args->pattern = argv[i++];

    if (i >= argc) return 1;
    args->filename = argv[i];

    return 0;
}
