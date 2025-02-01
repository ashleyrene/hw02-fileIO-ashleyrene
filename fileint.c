#include <stdio.h>
#include <stdbool.h>

bool addFile(const char *filename, int *sum) {
    *sum = 0; // Ensure sum starts from zero
    FILE *file = fopen(filename, "r");
    if (!file) {
        return false;
    }
    
    int num;
    while (fscanf(file, "%d", &num) == 1) {
        *sum += num;
    }
    
    fclose(file);
    return true;
}

bool writeSum(const char *filename, int sum) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        return false;
    }
    
    fprintf(file, "%d\n", sum);
    fclose(file);
    return true;
}
