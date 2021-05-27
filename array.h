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
void readArrayFromInputFile(ARRAY *array, const char *file_name);
bool addArray(ARRAY *array, RUNTIME_TYPE element);
bool removeArray(ARRAY *array, RUNTIME_TYPE element);
int sizeNrOfElementsArray(ARRAY array);
RUNTIME_TYPE getNthArray(ARRAY array, int n);
bool findArray(ARRAY array, RUNTIME_TYPE element);
void printArray(ARRAY array);
void destroyArray(ARRAY *array);

#endif //PROJECT_03_ARRAY_H
