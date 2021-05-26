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
bool appendListNode(ListNode **list, RUNTIME_TYPE value);
void deleteListNode(ListNode **node, RUNTIME_TYPE element);
int countListElements(ListNode *list);
int findElementInList(ListNode *node, RUNTIME_TYPE value);

#endif //PROJECT_03_LIST_H
