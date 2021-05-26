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
int heapParent(int i);
int heapLeft(int i);
int heapRight(int i);

bool insertHeap(Heap *heap, RUNTIME_TYPE value);
int countHeap(Heap *heap);

void rebalanceHeapAt(Heap *heap, int index);
void rebalanceHeapGlobally(Heap *heap, int index);

bool isHeapEmpty(Heap *heap);

int getHeapIndex(Heap *heap, RUNTIME_TYPE value);

void printHeap(Heap *heap);
void freeHeap(Heap *heap);

#endif //PROJECT_03_HEAP_H
