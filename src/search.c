#include <stdio.h>
#include <string.h>
#include "search.h"
#include "match.h"

int search_file(const char *pattern, const char *filename, int ignore_case,
		 int whole_word) {
 
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    char line[1024];

    while (fgets(line, sizeof(line), file) != NULL) {
       if (match_line(line, pattern, ignore_case, whole_word)) {
		printf("%s", line);
	}
    }

    fclose(file);
    return 0;
}
