#include <stdio.h>
#include "search.h"
#include "match.h"

static int search_input(FILE *file, const char *pattern,
                        int ignore_case, int whole_word,
                        int line_numbers, int count_only) {
    char line[1024];
    int line_num = 1;
    int count = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (match_line(line, pattern, ignore_case, whole_word)) {
            count++;

            if (!count_only) {
                if (line_numbers) {
                    printf("%d:%s", line_num, line);
                } else {
                    printf("%s", line);
                }
            }
        }

        line_num++;
    }

    if (count_only) {
        printf("%d\n", count);
    }

    return 0;
}

int search_file(const char *pattern, const char *filename,
                int ignore_case, int whole_word,
                int line_numbers, int count_only) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    int result = search_input(file, pattern, ignore_case, whole_word,
                              line_numbers, count_only);

    fclose(file);
    return result;
}

int search_stream(const char *pattern,
                  int ignore_case, int whole_word,
                  int line_numbers, int count_only) {
    return search_input(stdin, pattern, ignore_case, whole_word,
                        line_numbers, count_only);
}
