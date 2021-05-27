//
// Created by koppa on 2021. 05. 23..
//

#include "str_array.h"

STR_ARRAY createStrArray(int capacity){
    STR_ARRAY new_array;

    new_array.capacity = capacity;
    new_array.nr_elements = 0;
    new_array.elements = (char **) malloc(capacity * sizeof(char *));

    if (new_array.elements == NULL){
        printf("Error allocating memory!\n");
        exit(-1);
    }

    for (int i = 0; i < capacity; ++i){
        new_array.elements[i] = (char *) malloc(21 * sizeof(char));

        if (new_array.elements[i] == NULL){
            printf("Error allocating memory!\n");
            exit(-1);
        }
    }

    return new_array;
}

void readStrArrayFromInputFile(STR_ARRAY *array, const char *file_name){
    FILE *input_file = fopen(file_name, "r");

    if (input_file == NULL){
        printf("Error opening %s", file_name);
        exit(-1);
    }

    char *word = (char *) malloc(21 * sizeof(char));

    if (word == NULL){
        printf("Error allocating memory for word char pointer!\n");
        exit(-1);
    }

    while (fscanf(input_file, "%s\n", word) != EOF){
        addStrArray(array, word);
    }

    fclose(input_file);
}

bool addStrArray(STR_ARRAY *array, char *element){
    if (array->nr_elements == array->capacity){
        return false;
    }

    ++array->nr_elements;
    strcpy(array->elements[array->nr_elements - 1], element);
    array->elements[array->nr_elements - 1] = realloc(array->elements[array->nr_elements - 1], strlen(element) *
            sizeof(char *));

    return true;
}

bool removeStrArray(STR_ARRAY *array, const char *element){
    int pos = -1;

    for (int i = 0; i < array->nr_elements; ++i){
        if (strcmp(array->elements[i], element) == 0){
            pos = i;
            break;
        }
    }

    if (pos == -1){
        return false;
    }

    for (int i = pos; i < array->nr_elements - 1; ++i){
        strcpy(array->elements[i], array->elements[i + 1]);
    }

    --array->nr_elements;

    return true;
}

int sizeNrOfElementsStrArray(STR_ARRAY array){
    return array.nr_elements;
}

const char *getNthStrArray(STR_ARRAY array, int n){
    if (n > array.nr_elements){
        return NULL;
    }

    return array.elements[n - 1];
}

bool findStrArray(STR_ARRAY array, const char *element){
    for (int i = 0; i < array.nr_elements; ++i){
        if (strcmp(array.elements[i], element) == 0){
            return true;
        }
    }

    return false;
}

void printStrArray(STR_ARRAY array){
    for (int i = 0; i < array.nr_elements; ++i){
        printf("%s\n", array.elements[i]);
    }

    printf("\n");
}

void destroyStrArray(STR_ARRAY *array){
    for (int i = 0; i < array->nr_elements; ++i){
        free(array->elements[i]);
    }

    free(array->elements);

    array->nr_elements = 0;
    array->capacity = 0;

    array = NULL;
}