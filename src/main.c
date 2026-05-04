#include <stdio.h>
#include "args.h"
#include "search.h"

int main(int argc, char *argv[]) {
	struct Args args;

    if (parse_args( argc, argv, &args) != 0) {
	printf("Usage: %s [-i] [-w]  PATTERN FILE\n", argv[0]);
	return 1;
}




return search_file(args.pattern, args.filename,
			args.ignore_case, args.whole_word);

}

    
