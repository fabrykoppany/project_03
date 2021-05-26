#ifndef PROJECT_03_RUNTIME_TYPE_H
#define PROJECT_03_RUNTIME_TYPE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef enum RuntimeTypes {
    STRING,
    NUMBER
} RuntimeTypes;

typedef struct RUNTIME_TYPE {
    RuntimeTypes type : 1;
    void *data;
} RUNTIME_TYPE;

RUNTIME_TYPE createRuntimeType(RuntimeTypes type, void *data);
RUNTIME_TYPE createString(char *data);
RUNTIME_TYPE createNumber(long long data);

int printRuntimeType(RUNTIME_TYPE runtimeType);
RUNTIME_TYPE readRuntimeType(FILE *f);
bool areTypesEqual(RUNTIME_TYPE type1, RUNTIME_TYPE type2);
int compareTypes(RUNTIME_TYPE type1, RUNTIME_TYPE type2);
long long hashRuntimeType(RUNTIME_TYPE type);

#endif //PROJECT_03_RUNTIME_TYPE_H
