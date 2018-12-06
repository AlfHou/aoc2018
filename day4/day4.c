#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    int sleepTableCounter = 0;

    int startTime = 0;
    int endTime = 0;
    int totalTime = 0;

    int i;
    for (i = 0; i < lineCounter; i++) {
        int currentGuard;

        char *linePointer = &entries[i][0];
        char lineArray[10][10];
        int lineArrayCounter = 0;

        while (linePointer != NULL) {
            strcpy(lineArray[lineArrayCounter], strsep(&linePointer, " :"));
            lineArrayCounter++;
        }
        if (lineArray[4][0] == '#') {
            currentGuard = atoi(&lineArray[4][1]);  
        }
        if (strcmp(&lineArray[3][0], "falls") == 0) {
            startTime = atoi(&lineArray[2][0]);
        }
        if (strcmp(&lineArray[3][0], "wakes") == 0) {
            endTime = atoi(&lineArray[2][0]);
            totalTime = endTime - startTime;

            bool found = false;
            int j;
            for (j = 0; j < sleepTableCounter; j++) {
                if (sleepTable[j].id == currentGuard) {
                    sleepTable[j].sleep += totalTime;
                    found = true;
                }
            }
            if (!found) {
                struct guardSleep guard = {currentGuard, totalTime};
                sleepTable[sleepTableCounter] = guard;
                sleepTableCounter++;
            }
        }
    }
    //Find the guard that sleeps the most
    struct guardSleep currentSleepyGuard;
    int k;
    for (k = 0; k < sleepTableCounter; k++) {
        if (sleepTable[k].sleep > currentSleepyGuard.sleep) {
            currentSleepyGuard = sleepTable[k];
        }
    }
    
    //Find the minute currentSleepyGuard is most likely to sleep
    rewind(file);
    counter = 0;
    while(fgets(line, sizeof(line), file)) {
        strcpy(entries[counter], line);
        counter++;
    }
    qsort(entries, sizeof(entries)/sizeof(entries[0]), sizeof(entries[0]), compare);

    int hour[60];
    for (i = 0; i < lineCounter; i++) {
        int currentGuard;

        char *linePointer = &entries[i][0];
        char lineArray[10][10];
        int lineArrayCounter = 0;

        while (linePointer != NULL) {
            strcpy(lineArray[lineArrayCounter], strsep(&linePointer, " :"));
            lineArrayCounter++;
        }
        if (lineArray[4][0] == '#') {
            currentGuard = atoi(&lineArray[4][1]);
        }
        if (strcmp(&lineArray[3][0], "falls") == 0) {
            startTime = atoi(&lineArray[2][0]);
        }
        if (strcmp(&lineArray[3][0], "wakes") == 0) {
            endTime = atoi(&lineArray[2][0]);
            if (currentGuard == currentSleepyGuard.id) {
                int minute;
                for (minute = startTime; minute < endTime; minute++) {
                    hour[minute]++;
                }
            }
        }
    }
    int mostLikelyToSleep;
    int minute;
    for (minute = 0; minute < 60; minute++) {
        printf("minute: %d sleep: %d\n", minute, hour[minute]);
        if (hour[minute] > hour[mostLikelyToSleep]) {
            mostLikelyToSleep = minute;
        }
    }
    printf("Answer: %d\n", mostLikelyToSleep * currentSleepyGuard.id);

    fclose(file);
    exit(EXIT_SUCCESS);
}
