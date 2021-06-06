#ifndef PROJECT_03_HASHTABLE_H
#define PROJECT_03_HASHTABLE_H

#include "runtime_type.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct HashTable {
    int size;
    RUNTIME_TYPE *elements;
} HashTable;

HashTable *allocateHashTable(int n);
void freeHashTable(HashTable *table);
void readTableFromInputFile(HashTable *table, const char *file_name, int *comparisons, int *arithmetic);
bool insertHashTable(HashTable *table, RUNTIME_TYPE element, int *comparisons, int *arithmetic);
int findHashTable(HashTable *table, RUNTIME_TYPE element, int *comparisons, int *arithmetic);
bool removeHashTable(HashTable *table, RUNTIME_TYPE element, int *comparisons, int *arithmetic);
int countHashTable(HashTable *table, int *comparisons, int *arithmetic);
void printHashTable(HashTable *table);

RUNTIME_TYPE getWorstCaseTable(HashTable *table);
RUNTIME_TYPE getBestCaseTable(HashTable *table);
RUNTIME_TYPE getAvgCaseTable(HashTable *table);

#endif //PROJECT_03_HASHTABLE_H
