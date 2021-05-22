//
// Created by koppa on 2021. 05. 22..
//

#ifndef PROJECT_03_STRUCTURES_H
#define PROJECT_03_STRUCTURES_H

typedef struct{
    int size;
    int *elements;
}INT_ARRAY;

typedef struct{
    int size;
    char **elements;
}STR_ARRAY;

typedef struct NodeType{
    int element;
    struct NodeType *next;
}INT_LIST_T;

typedef struct NodeType{
    char *element;
    struct NodeType *next;
}STR_LIST_T;

// rest of structures

#endif //PROJECT_03_STRUCTURES_H
