 

#ifndef ARGS_H
#define ARGS_H

#define MAX_FILES 100

struct Args {
	int ignore_case;
	int whole_word;
	int line_numbers;
    int count_only;
	const char *pattern;
	const char *files[MAX_FILES];
    int file_count;
};
	
int parse_args(int argc, char *argv[], struct Args *args);

#endif
