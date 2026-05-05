CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -Iinclude

TARGET = grep-lite

SRC = src/main.c src/args.c src/search.c src/match.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
