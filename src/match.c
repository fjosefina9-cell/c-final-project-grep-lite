#include <string.h>
#include <ctype.h>
#include "match.h"

static void to_lower_str(const char *src, char *dst, int dst_size) {
    int i;
    for (i = 0; i < dst_size - 1 && src[i] != '\0'; i++) {
        dst[i] = (char)tolower((unsigned char)src[i]);
    }
    dst[i] = '\0';
}

static int is_word_char(char c) {
    return isalnum((unsigned char)c) || c == '_';
}

int match_line(const char *line, const char *pattern,
               int flag_i, int flag_w) {

    char low_line[4096];
    char low_pat[256];

    const char *search_line;
    const char *search_pat;

    if (flag_i) {
        to_lower_str(line,    low_line, sizeof(low_line));
        to_lower_str(pattern, low_pat,  sizeof(low_pat));
        search_line = low_line;
        search_pat  = low_pat;
    } else {
        search_line = line;
        search_pat  = pattern;
    }

    size_t pat_len = strlen(search_pat);
    if (pat_len == 0) return 1;

    const char *pos = search_line;
    while ((pos = strstr(pos, search_pat)) != NULL) {

        if (flag_w) {
            int left_ok  = (pos == search_line) || !is_word_char(*(pos - 1));
            int right_ok = !is_word_char(*(pos + pat_len));

            if (left_ok && right_ok) return 1;
        } else {
            return 1;
        }

        pos++;
    }

    return 0;
}
