#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int compare (const void * a, const void * b) {
    return strcmp (a, b);
}

struct guardSleep {
    int id;
    int sleep;
};

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
    qsort(entries, sizeof(entries)/sizeof(entries[0]), sizeof(entries[0]), compare);

    struct guardSleep sleepTable[lineCounter];
    
    
    fclose(file);
    exit(EXIT_SUCCESS);
}
