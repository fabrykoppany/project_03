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

void freeHashTable(HashTable *table) {
    free(table->elements);
    free(table);
}

bool insertHashTable(HashTable *table, RUNTIME_TYPE element) {
    int overflow = 0;

    do {
        long long index = (hashRuntimeType(element) + overflow) % table->size;
        RUNTIME_TYPE currentValue = table->elements[index];

        if (areTypesEqual(currentValue, element)) {
            // Already exists in the table
            return true;
        }

        if (areTypesEqual(currentValue, NO_ELEMENT)) {
            table->elements[index] = element;
            return true;
        }

        overflow++;
    } while (overflow != table->size);

    return false;
}

int findHashTable(HashTable *table, RUNTIME_TYPE element) {
    int overflow = 0;

    do {
        long long index = (hashRuntimeType(element) + overflow) % table->size;

        if (areTypesEqual(table->elements[index], element)) {
            return index;
        }

        overflow++;
    } while (overflow != table->size);

    return -1;
}

bool removeHashTable(HashTable *table, RUNTIME_TYPE element) {
    int index = findHashTable(table, element);

    if (index == -1) {
        return false;
    }

    table->elements[index] = NO_ELEMENT;
    return true;
}

int countHashTable(HashTable *table) {
    int count = 0;

    for (int i = 0; i < table->size; ++i) {
        if (!areTypesEqual(table->elements[i], NO_ELEMENT)) {
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