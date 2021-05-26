#ifndef PROJECT_03_HASHTABLE_H
#define PROJECT_03_HASHTABLE_H

#include "runtime_type.h"

#define NO_ELEMENT createNumber(-1)

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
bool insertHashTable(HashTable *table, RUNTIME_TYPE element);
int findHashTable(HashTable *table, RUNTIME_TYPE element);
bool removeHashTable(HashTable *table, RUNTIME_TYPE element);
int countHashTable(HashTable *table);
void printHashTable(HashTable *table);

#endif //PROJECT_03_HASHTABLE_H
