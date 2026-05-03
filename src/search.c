#include <stdio.h>
#include <string.h>
#include "search.h"

int search_file(const char *pattern, const char *filename) {
	(void)pattern; //temporary fix for error

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    char line[1024];

    while (fgets(line, sizeof(line), file) != NULL) {
       
	 /* TODO: search logic later */
    }

    fclose(file);
    return 0;
}
