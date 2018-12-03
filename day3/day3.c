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
        //Lager en char peker som peker til adressen
        //starten av line
        char *linePointer = line;
        strsep(&linePointer, " ,x");
        strsep(&linePointer, " ,x");
        char *xCoordinate = strsep(&linePointer, " ,x:");
        char *yCoordinate = strsep(&linePointer, " ,:x");
        //This is a little hard coded because the
        //strsep function doesnt allow multi-char delimiter
        strsep(&linePointer, ": ,:x");
        char *width = strsep(&linePointer, " ,:x");
        char *height = strsep(&linePointer, " ,:x");
        

        //endre elementet fra fabric[yCoordinate][xCoordinate] 
        //til og med fabric[yCoordinate + height][xCoordinate + widht]
        //til C (for counted) hvis elementet som allerede er der
        // == T eller til T (for taken) hvis ingenting er der fra før

        //Gå gjennom fabric og tell antall ganger den finner C
        
        


    }

    fclose(file);
    exit(EXIT_SUCCESS);
}
