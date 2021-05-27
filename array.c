#include "array.h"

ARRAY createArray(int capacity){
    ARRAY new_array;

    new_array.capacity = capacity;
    new_array.nr_elements = 0;
    new_array.elements = (RUNTIME_TYPE *) malloc(capacity * sizeof(RUNTIME_TYPE));

    if (new_array.elements == NULL){
        printf("Error allocating memory!\n");
        exit(-1);
    }

    return new_array;
}

void readArrayFromInputFile(ARRAY *array, const char *file_name){
    FILE *input_file = fopen(file_name, "r");

    if (input_file == NULL){
        printf("Error opening %s", file_name);
        exit(-1);
    }

    int n;
    fscanf(input_file, "%i", &n);

    for (int i = 0; i < n; ++i) {
        addArray(array, readRuntimeType(input_file));
    }

    fclose(input_file);
}

bool addArray(ARRAY *array, RUNTIME_TYPE element){
    if (array->nr_elements == array->capacity) {
        return false;
    }

    array->elements[array->nr_elements++] = element;
    return true;
}

bool removeArray(ARRAY *array, RUNTIME_TYPE element) {
    int pos = -1;

    for (int i = 0; i < array->nr_elements; ++i) {
        if (areTypesEqual(array->elements[i], element)) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        return false;
    }

    for (int i = pos; i < array->nr_elements - 1; ++i){
        array->elements[i] = array->elements[i + 1];
    }

    --array->nr_elements;
    return true;
}

int sizeNrOfElementsArray(ARRAY array){
    return array.nr_elements;
}

RUNTIME_TYPE getNthArray(ARRAY array, int n) {
    if (n > array.nr_elements) {
        return NO_ELEMENT;
    }

    return array.elements[n - 1];
}

bool findArray(ARRAY array, RUNTIME_TYPE element) {
    for (int i = 0; i < array.nr_elements; ++i){
        if (areTypesEqual(array.elements[i], element)) {
            return true;
        }
    }

    return false;
}

void printArray(ARRAY array){
    for (int i = 0; i < array.nr_elements; ++i){
        printRuntimeType(array.elements[i]);
        printf(" ");
    }

    printf("\n");
}

void destroyArray(ARRAY *array){
    for (int i = 0; i < array->nr_elements; ++i){
        freeRuntimeType(array->elements[i]);
    }

    free(array->elements);

    array->nr_elements = 0;
    array->capacity = 0;
}