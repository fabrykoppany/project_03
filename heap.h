#ifndef PROJECT_03_HEAP_H
#define PROJECT_03_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "runtime_type.h"

typedef struct Heap {
    int capacity;
    int size;
    RUNTIME_TYPE *array;
} Heap;

Heap *createHeap(int maxSize);
void readHeapFromInputFile(Heap *heap, const char *file_name, int *comparisons, int *arithmetic);

int heapParent(int i);
int heapLeft(int i);
int heapRight(int i);

bool insertHeap(Heap *heap, RUNTIME_TYPE value, int *comparisons, int *arithmetic);
int countHeap(Heap *heap);

void rebalanceHeapAt(Heap *heap, int index, int *comparisons, int *arithmetic);
void rebalanceHeapGlobally(Heap *heap, int index, int *comparisons, int *arithmetic);

bool isHeapEmpty(Heap *heap);

int getHeapIndex(Heap *heap, RUNTIME_TYPE value, int *comparisons, int *arithmetic);

void printHeap(Heap *heap);
void freeHeap(Heap *heap);

RUNTIME_TYPE getWorstCaseHeap(Heap *heap);
RUNTIME_TYPE getBestCaseHeap(Heap *heap);
RUNTIME_TYPE getAvgCaseHeap(Heap *heap);

#endif //PROJECT_03_HEAP_H
