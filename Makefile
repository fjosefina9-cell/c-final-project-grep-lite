CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -Iinclude

TARGET = grep-lite

SRC = src/main.c src/args.c src/search.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
