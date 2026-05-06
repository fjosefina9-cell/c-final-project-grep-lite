#include <string.h>
#include <ctype.h>
#include "match.h"

int match_line(const char *line, const char *pattern,
               int flag_i, int flag_w) {

    int i, j;
    int line_len = strlen(line);
    int pat_len = strlen(pattern);

    /* if pattern is empty, match everything */
    if (pat_len == 0) return 1;

    /* loop through every position in the line */
    for (i = 0; i <= line_len - pat_len; i++) {

        int found = 1;

        /* check if pattern matches at position i */
        for (j = 0; j < pat_len; j++) {
            char lc = line[i + j];
            char pc = pattern[j];

            /* if -i flag, ignore case */
            if (flag_i) {
                lc = tolower(lc);
                pc = tolower(pc);
            }

            if (lc != pc) {
                found = 0;
                break;
            }
        }

        /* if we found the pattern */
        if (found) {

            /* if -w flag, check word boundaries */
            if (flag_w) {
                if (i > 0 && isalnum(line[i - 1])) continue;
                if (i + pat_len < line_len && isalnum(line[i + pat_len])) continue;
            }

            return 1;
        }
    }

    return 0;
}
