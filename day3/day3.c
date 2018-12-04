#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char fabric[1000][1000];
    FILE *file = fopen("./input.txt", "r");

    //Fill the array with unclaimed spaces
    unsigned long i;
    for (i = 0; i < sizeof(fabric)/sizeof(fabric[0]); i++) {
        unsigned long j;
        for (j = 0; j < sizeof(fabric[0]); j++) {
            fabric[i][j] = '.';
        }    
    } 


    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *linePointer = line;
        strsep(&linePointer, " ,x:");
        strsep(&linePointer, " ,x:");

        char *xCoordinateString = strsep(&linePointer, " ,x:");
        long xCoordinate = strtol(xCoordinateString, NULL, 10);

        char *yCoordinateString = strsep(&linePointer, " ,:x");
        long yCoordinate = strtol(yCoordinateString, NULL, 10);

        strsep(&linePointer, " ,:x");

        char *widthString = strsep(&linePointer, " ,:x");
        long width = strtol(widthString, NULL, 10);

        char *heightString = strsep(&linePointer, " ,:x");
        long height = strtol(heightString, NULL, 10);

        long x;
        for (x = xCoordinate; x < xCoordinate + width; x++) {
            long y;
            for (y = yCoordinate; y < yCoordinate + height; y++) {
                if (fabric[x][y] == 'T') {
                    fabric[x][y] = 'C';
                } else if (fabric[x][y] != 'T' && fabric[x][y] != 'C') {
                    fabric[x][y] = 'T';
                }
            }
        }
    }
    
    int fabricCounter = 0;
    unsigned long x;
        for (x = 0; x < sizeof(fabric)/sizeof(fabric[0]); x++) {
            unsigned long y;
            for (y = 0; y < sizeof(fabric[0]); y++) {
                if (fabric[x][y] == 'C') {
                    fabricCounter++;
                }
            }
        } 
    printf("Overlapping claimed fabric: %d\n", fabricCounter);
    
    fclose(file);
    exit(EXIT_SUCCESS);
}
