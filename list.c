#include "list.h"

ListNode *createListNode() {
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));

    if (node == NULL) {
        return node;
    }

    node->next = NULL;
    return node;
}

void printList(ListNode *list) {
    ListNode *p = list;

    while (p != NULL) {
        printRuntimeType(p->info);
        printf(" ");
        p = p->next;
    }
}

bool appendListNode(ListNode **list, RUNTIME_TYPE value) {
    ListNode *element = createListNode();

    if (element == NULL) {
        return false;
    }

    element->info = value;

    if ((*list) == NULL) {
        (*list) = element;
        return true;
    }

    ListNode *p = (*list);

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = element;
    return true;
}

void deleteListNode(ListNode **head, RUNTIME_TYPE key) {
    ListNode *temp = *head;
    ListNode *prev = NULL;

    if (temp != NULL && areTypesEqual(temp->info, key)) {
        // Delete head
        (*head) = temp->next;
        freeRuntimeType(temp->info);
        free(temp);
        return;
    }

    while (temp != NULL && !areTypesEqual(temp->info, key)) {
        // Search for node
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        // Key not present
        return;
    }

    // Unlink node
    prev->next = temp->next;
    freeRuntimeType(temp->info);
    free(temp);
}

void freeList(ListNode **node) {
    ListNode *p = (*node);

    while (p != NULL) {
        ListNode *next = p->next;

        freeRuntimeType(p->info);
        free(p);
        p = next;
    }

    (*node) = NULL;
}

int countListElements(ListNode *list) {
    int count = 0;
    ListNode *p = list;

    while (p != NULL) {
        count++;
        p = p->next;
    }

    return count;
}

int findElementInList(ListNode *node, RUNTIME_TYPE value) {
    ListNode *p = node;
    int i = 0;

    while (p != NULL) {
        if (areTypesEqual(p->info, value)) {
            return i;
        }

        p = p->next;
        i++;
    }

    return -1;
}