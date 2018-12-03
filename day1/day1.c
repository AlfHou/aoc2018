#include <stdio.h>
#include <stdlib.h>

int findFrequency(void);
int findRepeatedFrequency(void);
int countLines(FILE *f);

int main(void) {
    printf("%d\n", findFrequency());
    printf("%d\n", findRepeatedFrequency());
}

int findFrequency(void) {
    int frequency = 0;
    FILE *inputFile;
    inputFile = fopen("./input.txt", "r");

    char line[100];
    while (fgets(line, 100, inputFile)) {
        int num = atoi(line);
        frequency += num;
    }
    fclose(inputFile);
    return frequency;
}

int findRepeatedFrequency(void) {
    int frequency = 0;

    FILE *inputFile;
    inputFile = fopen("./input.txt", "r");

    int log[200000];
    char line[100];

    int counter = 0;
    while (counter < 200000) {
        rewind(inputFile);
        while (fgets(line, 100, inputFile)) {
            log[counter] = frequency;
            int num = atoi(line);
            frequency += num;
            //Look through the log and look for duplicates, if duplicate found, return frequency
            int i;
            for (i = counter +1; i >= 0; i--) {
                if (frequency == log[i]) {
                    fclose(inputFile);
                    return frequency;
                }
            }
        counter++;
        }
    }
    fclose(inputFile);
    return 20;
}
