#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool existsIn(char c, char array[]) {
    int i;
    for (i = 0; i < strlen(array); i++) {
        if (array[i] == c) {
            return true;
        }
    }
    return false;
}
int findChecksum(FILE *file) {

    int numberOfThreeChars = 0;
    int numberOfTwoChars = 0;

    char line[40];
    while (fgets(line, 41, file)) {
        int strLength = strlen(line);

        bool threeChar = false;
        bool twoChar = false;

        char alreadyCounted[strLength];
        int alreadyCountedCounter = 0;
        
        int i;
        for (i = 0; i < strLength - 1; i++) {
            if (!existsIn(line[i], alreadyCounted)) {
                int count = 0;
                int j;
                for (j = 0; j < strLength - 1; j++) {
                    if (line[i] == line[j]) {
                        count++;
                    }
                }
                if (count == 3) {
                    threeChar = true;
                } else if (count == 2) {
                    twoChar = true;
                }
                alreadyCounted[alreadyCountedCounter] = line[i];
                alreadyCountedCounter++;
            }
        }

        if (threeChar) {
            numberOfThreeChars++;
        }
        if (twoChar) {
            numberOfTwoChars++;
        }
    }
    return numberOfThreeChars * numberOfTwoChars;
}

int main(void) {
    printf("Calculating checksum...\n");
    FILE *file;
    file = fopen("./input.txt", "r");

    int checksum = findChecksum(file);

    printf("Checksum: %d\n", checksum);

    fclose(file);
    exit(EXIT_SUCCESS);
}