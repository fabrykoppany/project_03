#include "runtime_type.h"

inline RUNTIME_TYPE createRuntimeType(RuntimeTypes type, void *data) {
    RUNTIME_TYPE runtimeType;

    runtimeType.type = type;
    runtimeType.data = data;
    return runtimeType;
}

inline RUNTIME_TYPE createString(char *data) {
    return createRuntimeType(STRING, data);
}

inline RUNTIME_TYPE createNumber(long long data) {
    return createRuntimeType(NUMBER, (void *) data);
}

inline int printRuntimeType(RUNTIME_TYPE runtimeType) {
    switch (runtimeType.type) {
        case STRING:
            return printf("%s", (const char *) runtimeType.data);
        case NUMBER:
            return printf("%lld", (long long) runtimeType.data);
        default:
            return printf("Error");
    }
}

inline RUNTIME_TYPE readRuntimeType(FILE *f) {
    char buffer[255];

    fscanf(f, "%s", buffer);

    char *endPtr = NULL;
    long long number = strtoll(buffer, &endPtr, 10);

    if (endPtr == NULL || (*endPtr) != '\0') {
        // We couldn't convert the string to a long long,
        // so it must be a character string.
        // Transfer our string to the heap.
        char *savedString = (char *) malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(savedString, buffer);
        return createString(savedString);
    }

    return createNumber(number);
}

inline bool areTypesEqual(RUNTIME_TYPE type1, RUNTIME_TYPE type2) {
    if (type1.type != type2.type) {
        // Since their types are not equal
        // they can never be equal
        return false;
    }

    switch (type1.type) {
        case STRING:
            return strcmp(type1.data, type2.data) == 0;
        case NUMBER:
            return ((long long) type1.data) == ((long long) type2.data);
        default:
            return false;
    }
}

inline int compareTypes(RUNTIME_TYPE type1, RUNTIME_TYPE type2) {
    if (type1.type != type2.type) {
        return -1;
    }

    switch (type1.type) {
        case STRING:
            return strcmp(type1.data, type2.data);
        case NUMBER:
            return (type1.data > type2.data) ? 1 : -1;
        default:
            return -1;
    }
}

inline long long hashRuntimeType(RUNTIME_TYPE type) {
    switch (type.type) {
        case STRING: {
            int hash = 0;
            char *data = (char *) type.data;

            // Our hash is simple: just add together all letter ASCII codes
            for (int i = 0; i < strlen(data); ++i) {
                hash += data[i];
            }

            return hash;
        }
        case NUMBER:
            // smaller cast is fine
            return (long long) type.data;
        default:
            return -1;
    }
}

inline void freeRuntimeType(RUNTIME_TYPE type) {
    if (type.type == STRING && type.data != NULL) {
        free((char *) type.data);
        type.data = NULL;
    }
}