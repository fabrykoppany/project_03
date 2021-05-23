//
// Created by koppa on 2021. 05. 23..
//

#ifndef PROJECT_03_STR_ARRAY_H
#define PROJECT_03_STR_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "structures.h"

STR_ARRAY createStrArray(int capacity);
void readStrArrayFromInputFile(STR_ARRAY *array, const char *file_name);
bool addStrArray(STR_ARRAY *array, char *element);
bool removeStrArray(STR_ARRAY *array, const char *element);
int sizeNrOfElementsStrArray(STR_ARRAY array);
const char *getNthStrArray(STR_ARRAY array, int n);
bool findStrArray(STR_ARRAY array, const char *element);
void printStrArray(STR_ARRAY array);
void destroyStrArray(STR_ARRAY *array);

#endif //PROJECT_03_STR_ARRAY_H
