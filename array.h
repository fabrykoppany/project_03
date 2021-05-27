#ifndef PROJECT_03_ARRAY_H
#define PROJECT_03_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "runtime_type.h"

typedef struct{
    int capacity, nr_elements;
    RUNTIME_TYPE *elements;
} ARRAY;

ARRAY createArray(int capacity);
void readArrayFromInputFile(ARRAY *array, const char *file_name, int *comparisons, int *arithmetic);
bool addArray(ARRAY *array, RUNTIME_TYPE element, int *comparisons, int *arithmetic);
bool removeArray(ARRAY *array, RUNTIME_TYPE element, int *comparisons, int *arithmetic);
int sizeNrOfElementsArray(ARRAY array);
RUNTIME_TYPE getNthArray(ARRAY array, int n);
bool findArray(ARRAY array, RUNTIME_TYPE element, int *comparisons, int *arithmetic);
void printArray(ARRAY array);
void destroyArray(ARRAY *array);

RUNTIME_TYPE getWorstCaseArray(ARRAY *array);
RUNTIME_TYPE getBestCaseArray(ARRAY *array);
RUNTIME_TYPE getAvgCaseArray(ARRAY *array);

#endif //PROJECT_03_ARRAY_H
