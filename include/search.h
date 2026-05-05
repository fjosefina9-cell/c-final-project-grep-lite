

#ifndef SEARCH_H
#define SEARCH_H

int search_file(const char *pattern, const char *filename,
		int ignore_case, int whole_world, int line_numbers, 
		int count_only);
int search_stream(const char *pattern, int ignore_case, int whole_word,
		int line_numbers, int count_only);
#endif
