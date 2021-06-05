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

void readArrayFromInputFile(ARRAY *array, const char *file_name, int *comparisons, int *arithmetic){
    FILE *input_file = fopen(file_name, "r");

    (*comparisons) = (*comparisons) + 1;

    if (input_file == NULL){
        printf("Error opening %s", file_name);
        exit(-1);
    }

    int n;
    fscanf(input_file, "%i", &n);

    for (int i = 0; i < n; *arithmetic = *arithmetic + 1, (*comparisons) = (*comparisons) + 1, ++i) {
        addArray(array, readRuntimeType(input_file), comparisons, arithmetic);
    }

    fclose(input_file);
}

bool addArray(ARRAY *array, RUNTIME_TYPE element, int *comparisons, int *arithmetic) {
    (*comparisons) = (*comparisons) + 1;

    if (array->nr_elements == array->capacity) {
        return false;
    }

    (*arithmetic) = (*arithmetic) + 1;
    array->elements[array->nr_elements++] = element;
    return true;
}

bool removeArray(ARRAY *array, RUNTIME_TYPE element, int *comparisons, int *arithmetic) {
    int pos = -1;

    for (int i = 0; i < array->nr_elements; *arithmetic = *arithmetic + 1, ++i) {
        (*comparisons) = (*comparisons) + 1;

        if (areTypesEqual(array->elements[i], element)) {
            pos = i;
            break;
        }
    }

    (*comparisons) = (*comparisons) + 1;

    if (pos == -1) {
        return false;
    }

    for (int i = pos; i < array->nr_elements - 1; ++i){
        (*comparisons) = (*comparisons) + 1;
        (*arithmetic) = (*arithmetic) + 2;
        array->elements[i] = array->elements[i + 1];
    }

    (*arithmetic) = (*arithmetic) + 1;
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

bool findArray(ARRAY array, RUNTIME_TYPE element, int *comparisons, int *arithmetic) {
    for (int i = 0; i < array.nr_elements; ++i){
        (*comparisons) = (*comparisons) + 2;
        (*arithmetic) = (*arithmetic) + 1;

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

RUNTIME_TYPE getWorstCaseArray(ARRAY *array) {
    return array->elements[array->nr_elements - 1];
}

RUNTIME_TYPE getBestCaseArray(ARRAY *array) {
    return array->elements[0];
}

RUNTIME_TYPE getAvgCaseArray(ARRAY *array) {
    return array->elements[array->nr_elements / 2];
}