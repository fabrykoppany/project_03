//
// Created by koppa on 2021. 05. 22..
//

#ifndef PROJECT_03_INT_ARRAY_H
#define PROJECT_03_INT_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "structures.h"

INT_ARRAY createIntArray(int capacity);
void readIntArrayFromInputFile(INT_ARRAY *array, const char *file_name);
bool addIntArray(INT_ARRAY *array, int element);
bool removeIntArray(INT_ARRAY *array, int element);
int sizeNrOfElementsIntArray(INT_ARRAY array);
int getNthIntArray(INT_ARRAY array, int n);
bool findIntArray(INT_ARRAY array, int element);
void printIntArray(INT_ARRAY array);
void destroyIntArray(INT_ARRAY *array);

#endif //PROJECT_03_INT_ARRAY_H
