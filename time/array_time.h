//
// Created by koppa on 2021. 05. 23..
//

#ifndef PROJECT_03_INT_ARRAY_TIME_H
#define PROJECT_03_INT_ARRAY_TIME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../array.h"
#include "../file.h"
#include "../runtime_type.h"

void bestCaseArray(const char *type, RUNTIME_TYPE element);
void worstCaseArray(const char *type, RUNTIME_TYPE element);
void avgCaseArray(const char *type);

#endif //PROJECT_03_INT_ARRAY_TIME_H
