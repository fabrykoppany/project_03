#include "heap.h"

// TODO: Remove from heap

Heap *createHeap(int maxSize) {
    Heap *heap = (Heap *) malloc(sizeof(Heap));

    if (heap == NULL) {
        printf("Could not allocate memory.\n");
        return NULL;
    }

    heap->array = (RUNTIME_TYPE *) malloc(maxSize * sizeof(RUNTIME_TYPE));

    if (heap->array == NULL) {
        printf("Could not allocate memory.\n");
        free(heap);
        return NULL;
    }

    heap->capacity = maxSize;
    heap->size = 0;
    return heap;
}

inline int heapParent(int i) {
    return (i - 1) / 2;
}

inline int heapLeft(int i) {
    return (2 * i) + 1;
}

inline int heapRight(int i) {
    return (2 * i) + 2;
}

bool insertHeap(Heap *heap, RUNTIME_TYPE value) {
    if (heap->size >= heap->capacity) {
        return false;
    }

    int i = (heap->size++);

    heap->array[i] = value;
    rebalanceHeapAt(heap, i);
}

int countHeap(Heap *heap) {
    return heap->size;
}

void rebalanceHeapAt(Heap *heap, int index) {
    int parent = heapParent(index);

    while (index != 0 && compareTypes(heap->array[parent], heap->array[index]) > 0) {
        RUNTIME_TYPE a = heap->array[index];
        heap->array[index] = heap->array[parent];
        heap->array[parent] = a;

        index = parent;
        parent = heapParent(index);
    }
}

void rebalanceHeapGlobally(Heap *heap, int index) {
    int left = heapLeft(index);
    int right = heapRight(index);
    int smallest = index;

    if (left < heap->size && compareTypes(heap->array[left], heap->array[smallest]) < 0) {
        smallest = left;
    }

    if (right < heap->size && compareTypes(heap->array[right], heap->array[smallest]) < 0) {
        smallest = right;
    }

    if (smallest != index) {
        RUNTIME_TYPE a = heap->array[index];
        heap->array[index] = heap->array[smallest];
        heap->array[smallest] = a;

        rebalanceHeapGlobally(heap, smallest);
    }
}

bool isHeapEmpty(Heap *heap) {
    return heap->size == 0;
}

int getHeapIndex(Heap *heap, RUNTIME_TYPE value) {
    for (int i = 0; i < heap->size; ++i) {
        if (areTypesEqual(heap->array[i], value)) {
            return i;
        }
    }

    return -1;
}

void printHeap(Heap *heap) {
    for (int i = 0; i < heap->size; ++i) {
        printRuntimeType(heap->array[i]);
        printf(" ");
    }

    printf("\n");
}

void freeHeap(Heap *heap) {
    for (int i = 0; i < heap->size; ++i) {
        freeRuntimeType(heap->array[i]);
    }

    free(heap->array);
    free(heap);
}