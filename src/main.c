#include <stdio.h>

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    FILE *file = fopen("data/test.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char line[256];

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}
