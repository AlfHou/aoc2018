#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char *fabric[1000][1000];
    FILE *file = fopen("./input.txt", "r");

    //Her lager jeg en array med størrelse 256 som er
    //deklarert til å inneholde char
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *id;
        //Lager en char peker som peker til adressen
        //starten av line
        char *linePointer = line;
        //Her sender jeg inn en peker til den pekeren som
        //peker på første element i arrayen 'line'
        //Den returnerer en peker til 
        id = strsep(&linePointer, " ,x");
        strsep(&linePointer, " ,x");
        char *xCoordinate = strsep(&linePointer, " ,x:");
        char *yCoordinate = strsep(&linePointer, " ,:x");
        //This is a little hard coded because the
        //strsep function doesnt allow multi-char delimiter
        strsep(&linePointer, ": ,:x");
        char *width = strsep(&linePointer, " ,:x");
        char *height = strsep(&linePointer, " ,:x");
        
        


    }

    fclose(file);
    exit(EXIT_SUCCESS);
}
