#include <stdio.h>
#include <string.h>
#include "search.h"
#include "match.h"

int search_file(const char *pattern, const char *filename) {
 
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    char line[1024];

    while (fgets(line, sizeof(line), file) != NULL) {
       if (match_line(line, pattern, 0, 0)) {
		printf("%s", line);
	}
    }

    fclose(file);
    return 0;
}
