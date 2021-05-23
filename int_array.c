//
// Created by koppa on 2021. 05. 22..
//

#include "int_array.h"

INT_ARRAY createIntArray(int capacity){
    INT_ARRAY new_array;

    new_array.capacity = capacity;
    new_array.nr_elements = 0;
    new_array.elements = (int *) malloc(capacity * sizeof(int));

    if (new_array.elements == NULL){
        printf("Error allocating memory!\n");
        exit(-1);
    }

    return new_array;
}

void readIntArrayFromInputFile(INT_ARRAY *array, const char *file_name){
    FILE *input_file = fopen(file_name, "r");

    if (input_file == NULL){
        printf("Error opening %s", file_name);
        exit(-1);
    }

    int num;

    while (fscanf(input_file, "%i", &num) != EOF){
        addIntArray(array, num);
    }

    fclose(input_file);
}

bool addIntArray(INT_ARRAY *array, int element){
    if (array->nr_elements == array->capacity){
        return false;
    }

    ++array->nr_elements;
    array->elements[array->nr_elements - 1] = element;

    return true;
}

bool removeIntArray(INT_ARRAY *array, int element){
    int pos = -1;

    for (int i = 0; i < array->nr_elements; ++i){
        if (array->elements[i] == element){
            pos = i;
            break;
        }
    }

    if (pos == -1){
        return false;
    }

    for (int i = pos; i < array->nr_elements - 1; ++i){
        array->elements[i] = array->elements[i + 1];
    }

    --array->nr_elements;

    return true;
}

bool findIntArray(INT_ARRAY array, int element){
    for (int i = 0; i < array.nr_elements; ++i){
        if (array.elements[i] == element){
            return true;
        }
    }

    return false;
}

int sizeNrOfElementsIntArray(INT_ARRAY array){
    return array.nr_elements;
}

int getNthIntArray(INT_ARRAY array, int n){
    if (n > array.nr_elements){
        return -1;
    }

    return array.elements[n - 1];
}

void printIntArray(INT_ARRAY array){
    for (int i = 0; i < array.nr_elements; ++i){
        printf("%i\n", array.elements[i]);
    }

    printf("\n");
}

void destroyIntArray(INT_ARRAY *array){
    free(array->elements);
    array->capacity = 0;
    array->nr_elements = 0;

    array = NULL;
}