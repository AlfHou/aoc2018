#include <stdlib.h>
#include <stdio.h>

int getNumberOfChar(FILE *file) {
    int counter = 0;
        while (fgetc(file) != -1) {
            counter++;
        }
        rewind(file);
        return counter;
}

void readFileToArray(FILE *file, char array[], int arrayLength) {
    while(fgets(array, arrayLength, file)) {
    }
}

int main(void) {
    FILE * file;
    file = fopen("./input.txt", "r");

    int counter = getNumberOfChar(file);

    char characterArray[counter];
    
    //For example, when an array is passed to a function or is assigned to a pointer,
    //it decays into (implicitly converted to) a pointer.
    //Exceptions: when the array is the argument of the `&` (address-of) operator:
    readFileToArray(file, characterArray, sizeof(characterArray));

    fclose(file);
    exit(EXIT_SUCCESS);
}
