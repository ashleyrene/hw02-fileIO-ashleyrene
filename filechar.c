#include <stdio.h>
#include <stdbool.h>

bool countChar(const char *filename, int *counts, int size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return false;
    }
    
    int onechar;
    while ((onechar = fgetc(file)) != EOF) {
        if (onechar >= 0 && onechar < size) {
            counts[onechar]++;
        }
    }
    
    fclose(file);
    return true;
}

void printCounts(const int *counts, int size) {
    for (int i = 0; i < size; i++) {
        if (counts[i] > 0) {
            char displayChar = (i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z') ? (char)i : ' ';
            printf("%d, %c, %d\n", i, displayChar, counts[i]);
        }
    }
}
