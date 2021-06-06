#include "hashtable.h"

HashTable *allocateHashTable(int n) {
    HashTable *table = (HashTable *) malloc(sizeof(HashTable));

    if (table == NULL) {
        printf("Could not allocate memory!\n");
        return NULL;
    }

    table->elements = (RUNTIME_TYPE *) malloc(n * sizeof(RUNTIME_TYPE));

    if (table->elements == NULL) {
        free(table);
        printf("Could not allocate memory!\n");
        return NULL;
    }

    for (int i = 0; i < n; ++i) {
        table->elements[i] = NO_ELEMENT;
    }

    table->size = n;
    return table;
}

void readTableFromInputFile(HashTable *table, const char *file_name, int *comparisons, int *arithmetic) {
    FILE *input_file = fopen(file_name, "r");

    (*comparisons) = (*comparisons) + 1;

    if (input_file == NULL) {
        printf("Error opening %s", file_name);
        exit(-1);
    }

    int n;
    fscanf(input_file, "%i", &n);

    for (int i = 0; i < n; ++i) {
        insertHashTable(table, readRuntimeType(input_file), comparisons, arithmetic);
    }

    fclose(input_file);
}

void freeHashTable(HashTable *table) {
    for (int i = 0; i < table->size; ++i) {
        freeRuntimeType(table->elements[i]);
    }

    free(table->elements);
    free(table);
}

bool insertHashTable(HashTable *table, RUNTIME_TYPE element, int *comparisons, int *arithmetic) {
    int overflow = 0;

    do {
        long long index = (hashRuntimeType(element) + overflow) % table->size;
        RUNTIME_TYPE currentValue = table->elements[index];

        (*arithmetic) = (*arithmetic) + 2;
        (*comparisons) = (*comparisons) + 1;

        if (areTypesEqual(currentValue, element)) {
            // Already exists in the table
            return true;
        }

        (*comparisons) = (*comparisons) + 1;

        if (areTypesEqual(currentValue, NO_ELEMENT)) {
            table->elements[index] = element;
            return true;
        }

        (*arithmetic) = (*arithmetic) + 1;
        (*comparisons) = (*comparisons) + 1;
        overflow++;
    } while (overflow != table->size);

    return false;
}

int findHashTable(HashTable *table, RUNTIME_TYPE element, int *comparisons, int *arithmetic) {
    int overflow = 0;

    do {
        long long index = (hashRuntimeType(element) + overflow) % table->size;

        (*comparisons) = (*comparisons) + 1;
        (*arithmetic) = (*arithmetic) + 2;

        if (areTypesEqual(table->elements[index], element)) {
            return index;
        }

        (*comparisons) = (*comparisons) + 1;
        (*arithmetic) = (*arithmetic) + 1;
        overflow++;
    } while (overflow != table->size);

    return -1;
}

bool removeHashTable(HashTable *table, RUNTIME_TYPE element, int *comparisons, int *arithmetic) {
    int index = findHashTable(table, element, comparisons, arithmetic);

    (*comparisons) = (*comparisons) + 1;

    if (index == -1) {
        return false;
    }

    table->elements[index] = NO_ELEMENT;
    return true;
}

int countHashTable(HashTable *table, int *comparisons, int *arithmetic) {
    int count = 0;

    for (int i = 0; i < table->size; ++i) {
        (*comparisons) = (*comparisons) + 2;
        (*arithmetic) = (*arithmetic) + 1;

        if (!areTypesEqual(table->elements[i], NO_ELEMENT)) {
            (*arithmetic) = (*arithmetic) + 1;
            count++;
        }
    }

    return count;
}

void printHashTable(HashTable *table) {
    for (int i = 0; i < table->size; ++i) {
        if (!areTypesEqual(table->elements[i], NO_ELEMENT)) {
            printRuntimeType(table->elements[i]);
            printf(" ");
        }
    }

    printf("\n");
}

RUNTIME_TYPE getWorstCaseTable(HashTable *table) {
    RUNTIME_TYPE element;

    for (int i = 0; i < table->size; ++i) {
        if (!areTypesEqual(table->elements[i], NO_ELEMENT)) {
            element = table->elements[i];

            if (hashRuntimeType(element) != i) {
                return element;
            }
        }
    }

    return element;
}

RUNTIME_TYPE getBestCaseTable(HashTable *table) {
    RUNTIME_TYPE element;

    for (int i = 0; i < table->size; ++i) {
        if (!areTypesEqual(table->elements[i], NO_ELEMENT)) {
            element = table->elements[i];

            if (hashRuntimeType(element) == i) {
                return element;
            }
        }
    }

    return element;
}

RUNTIME_TYPE getAvgCaseTable(HashTable *table) {
    RUNTIME_TYPE element;

    for (int i = 0; i < table->size; ++i) {
        if (!areTypesEqual(table->elements[i], NO_ELEMENT)) {
            element = table->elements[i];

            if (rand() % 4 == 0) {
                return element;
            }
        }
    }

    return element;
}