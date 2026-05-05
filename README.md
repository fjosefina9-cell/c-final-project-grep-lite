# grep-lite

##summary of project:
	a grep-lite search tool written in C.

## features
	- search for a patternin files or standard input
	- case-insensitive search ('-i') 
	- whole-word matching('-w')
	- show line numbers('-n')
	- count matches ('c')
	- supports multiple files
	- supports input via pipes

## Project Structure

c-final-project-grep-lite/
|____ data/
|	|___test.txt
|_____include/
|	|___args.h
|	|___match.h
|	|___search.h
|______src/
|	|___args.c
|	|___main.c
|	|___match.c
|	|___search.c
|_______tests/
|	|_test_basic.sh
|_______.gitignore
|_______Makefile
|_______README.md


## build

compile the project:
make

remove compiled files:
make clean

## Case-Insensitive search:
	use '-i' to ignore uppercase/lowercase differences
		./grep-lite -i HELLO data/test.txt

## Whole word matching
	use '-w' to match only complete words
		./grep-lite -w hello data/test.txt

## line number output
	use '-n' to display matching line numbers
		./grep-lite -n hello data/test.txt

## count matches 
	use '-c' to display only the number of matching lines
		./grep-lite -c hello data/test.txt

## combined flags
	flags can be combined together
		./grep-lite -iw hello data/test.txt

##standard input (pipe support)
	search text from standard input
		cat data/test.txt | ./grep-lite hello
		(cat prints the contents of the file to the terminal)
	
		echo "hello world" | ./grep-lite hello
		(echo prints text within " ")
## example contents of data/test.txt
	hello world
	HELLO AGAIN
	hello again test
	helloagain
	sayhello

## authors
	- josefina
	- marc
	- om
	- justin
make 
