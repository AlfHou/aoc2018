#include <stdlib.h>
#include <stdio.h>

int main(void) {
    FILE *file;
    file = fopen("./input.txt", "r");
    fclose(file);


    exit(EXIT_SUCCESS);
}