//
// Created by koppa on 2021. 05. 22..
//

#ifndef PROJECT_03_STRUCTURES_H
#define PROJECT_03_STRUCTURES_H

typedef struct{
    int capacity, nr_elements;
    int *elements;
}INT_ARRAY;

typedef struct{
    int capacity, nr_elements;
    char **elements;
}STR_ARRAY;

typedef struct INT_LIST{
    int element;
    struct INT_LIST *next;
}INT_LIST_T;

typedef struct STR_ARRAY{
    char *element;
    struct STR_ARRAY *next;
}STR_LIST_T;

// rest of structures

#endif //PROJECT_03_STRUCTURES_H
