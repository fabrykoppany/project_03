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

void readHeapFromInputFile(Heap *heap, const char *file_name, int *comparisons, int *arithmetic) {
    FILE *input_file = fopen(file_name, "r");

    (*comparisons) = (*comparisons) + 1;

    if (input_file == NULL) {
        printf("Error opening %s", file_name);
        exit(-1);
    }

    int n;
    fscanf(input_file, "%i", &n);

    for (int i = 0; i < n; ++i) {
        insertHeap(heap, readRuntimeType(input_file), comparisons, arithmetic);
    }

    fclose(input_file);
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

bool insertHeap(Heap *heap, RUNTIME_TYPE value, int *comparisons, int *arithmetic) {
    (*comparisons) = (*comparisons) + 1;

    if (heap->size >= heap->capacity) {
        return false;
    }

    (*arithmetic) = (*arithmetic) + 1;
    int i = (heap->size++);

    heap->array[i] = value;
    rebalanceHeapAt(heap, i, comparisons, arithmetic);
}

int countHeap(Heap *heap) {
    return heap->size;
}

void rebalanceHeapAt(Heap *heap, int index, int *comparisons, int *arithmetic) {
    int parent = heapParent(index);

    (*arithmetic) = (*arithmetic) + 2;
    (*comparisons) = (*comparisons) + 2;

    while (index != 0 && compareTypes(heap->array[parent], heap->array[index]) > 0) {
        // heapParent arithmetics
        (*arithmetic) = (*arithmetic) + 2;
        (*comparisons) = (*comparisons) + 2;

        RUNTIME_TYPE a = heap->array[index];
        heap->array[index] = heap->array[parent];
        heap->array[parent] = a;

        index = parent;
        parent = heapParent(index);
    }
}

void rebalanceHeapGlobally(Heap *heap, int index, int *comparisons, int *arithmetic) {
    int left = heapLeft(index);
    int right = heapRight(index);
    int smallest = index;

    (*comparisons) = (*comparisons) + 7;
    (*arithmetic) = (*arithmetic) + 4;

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

        rebalanceHeapGlobally(heap, smallest, comparisons, arithmetic);
    }
}

bool isHeapEmpty(Heap *heap) {
    return heap->size == 0;
}

int getHeapIndex(Heap *heap, RUNTIME_TYPE value, int *comparisons, int *arithmetic) {
    for (int i = 0; i < heap->size; ++i) {
        (*comparisons) = (*comparisons) + 2;
        (*arithmetic) = (*arithmetic) + 1;

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

RUNTIME_TYPE getWorstCaseHeap(Heap *heap) {
    return heap->array[heap->size - 1];
}

RUNTIME_TYPE getBestCaseHeap(Heap *heap) {
    return heap->array[0];
}

RUNTIME_TYPE getAvgCaseHeap(Heap *heap) {
    return heap->array[(heap->size - 1) / 2];
}