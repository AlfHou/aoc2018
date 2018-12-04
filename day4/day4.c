#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *file;
    file = fopen("./input.txt", "r");
    char line[256];
    int counter = 0;
    while(fgets(line, sizeof(line), file)) {
        
    }
    fclose(file);
    exit(EXIT_SUCCESS);
}
