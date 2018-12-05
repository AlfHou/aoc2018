#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *file;
    file = fopen("./input.txt", "r");

    char line[256];
    int lineCounter = 0;
    while(fgets(line, sizeof(line), file)) {
        lineCounter++;
    }
    rewind(file);
    
    char entries[lineCounter][256];
    int counter = 0;
    while(fgets(line, sizeof(line), file)) {
        strcpy(entries[counter], line);
        counter++;
    }
    
    fclose(file);
    exit(EXIT_SUCCESS);
}
