#ifndef PROJECT_03_LIST_H
#define PROJECT_03_LIST_H

#include "runtime_type.h"

typedef struct ListNode {
    RUNTIME_TYPE info;
    struct ListNode *next;
} ListNode;

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

ListNode *createListNode();
void printList(ListNode *list);
void readListFromInputFile(ListNode **list, const char *file_name, int *comparisons);
ListNode *appendListNode(ListNode **list, RUNTIME_TYPE value, int *comparisons);
void deleteListNode(ListNode **node, RUNTIME_TYPE element, int *comparisons);
void freeList(ListNode **node);
int countListElements(ListNode *list);
int findElementInList(ListNode *node, RUNTIME_TYPE value, int *comparisons, int *arithmetic);

RUNTIME_TYPE getWorstCaseList(ListNode *node);
RUNTIME_TYPE getBestCaseList(ListNode *node);
RUNTIME_TYPE getAvgCaseList(ListNode *node);

#endif //PROJECT_03_LIST_H
