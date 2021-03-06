#ifndef PROJECT_03_INT_ARRAY_TIME_H
#define PROJECT_03_INT_ARRAY_TIME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../array.h"
#include "../file.h"
#include "../runtime_type.h"
#include "../list.h"
#include "../btree.h"
#include "../hashtable.h"
#include "../heap.h"

typedef enum TestType {
    TEST_ARRAY,
    TEST_LIST,
    TEST_BTREE,
    TEST_HEAP,
    TEST_HASHTABLE
} TestType;

void bestCaseTest(TestType test, const char *type, RUNTIME_TYPE element);
void worstCaseTest(TestType test, const char *type, RUNTIME_TYPE element);
void avgCaseTest(TestType test, const char *type);

#endif //PROJECT_03_INT_ARRAY_TIME_H
