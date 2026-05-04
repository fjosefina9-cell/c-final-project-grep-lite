 

#ifndef ARGS_H
#define ARGS_H

/* placeholder for argument parsing functions */
struct Args {
	int ignore_case;
	int whole_word;
	const char *pattern;
	const char *filename;
};
	
int parse_args(int argc, char *argv[], struct Args *args);

#endif
