#include <stdio.h>
#include <stdbool.h>

bool countChar(const char *filename, int *counts, int size) 
{
    // open a file whose name is filename for reading
    FILE *file = fopen(filename, "r");
    // if fopen fails, return false. Do NOT fclose
    if (!file) {
        return false;
    }

    // if fopen succeeds, read every character from the file
    int onechar;
    while ((onechar = fgetc(file)) != EOF) 
    {
        // if a character (call it onechar) is between
        // 0 and size - 1 (inclusive), increase counts[onechar] by one
        if (onechar >= 0 && onechar < size) 
        {
            counts[onechar]++;
        }
    }

    // remember to call fclose
    fclose(file);
    return true;
}

void printCounts(const int *counts, int size) 
{
    // print the values in counts in the following format
    for (int i = 0; i < size; i++) 
    {
        // each line has three items:
        // ind, onechar, counts[ind]
        // ind is between 0 and size - 1 (inclusive)
        if (counts[i] > 0) 
        {
            // onechar is printed if ind is between 'a' and 'z' or 'A' and 'Z'. Otherwise, print space
            char displayChar = (i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z') ? (char)i : ' ';
            printf("%d, %c, %d\n", i, displayChar, counts[i]);
        }
    }
}
