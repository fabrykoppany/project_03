#include "list.h"

ListNode *createListNode() {
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));

    if (node == NULL) {
        return node;
    }

    node->next = NULL;
    node->info = NO_ELEMENT;
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

void readListFromInputFile(ListNode **list, const char *file_name, int *comparisons) {
    FILE *input_file = fopen(file_name, "r");

    (*comparisons) = (*comparisons) + 1;

    if (input_file == NULL) {
        printf("Error opening %s", file_name);
        exit(-1);
    }

    int n;
    fscanf(input_file, "%i", &n);
    ListNode *p = (*list);

    for (int i = 0; i < n; ++i) {
        p = appendListNode(&p, readRuntimeType(input_file), comparisons);
    }

    fclose(input_file);
}

ListNode *appendListNode(ListNode **list, RUNTIME_TYPE value, int *comparisons) {
    ListNode *element = createListNode();

    (*comparisons) = (*comparisons) + 1;

    if (element == NULL) {
        return NULL;
    }

    element->info = value;

    (*comparisons) = (*comparisons) + 1;

    if ((*list) == NULL) {
        (*list) = element;
        return element;
    }

    ListNode *p = (*list);

    while (p->next != NULL) {
        (*comparisons) = (*comparisons) + 1;
        p = p->next;
    }

    p->next = element;
    return element;
}

void deleteListNode(ListNode **head, RUNTIME_TYPE key, int *comparisons) {
    ListNode *temp = *head;
    ListNode *prev = NULL;

    (*comparisons) = (*comparisons) + 2;

    if (temp != NULL && areTypesEqual(temp->info, key)) {
        // Delete head
        (*head) = temp->next;
        freeRuntimeType(temp->info);
        free(temp);
        return;
    }

    while (temp != NULL && !areTypesEqual(temp->info, key)) {
        (*comparisons) = (*comparisons) + 2;

        // Search for node
        prev = temp;
        temp = temp->next;
    }

    (*comparisons) = (*comparisons) + 1;

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

int findElementInList(ListNode *node, RUNTIME_TYPE value, int *comparisons, int *arithmetic) {
    ListNode *p = node;
    int i = 0;

    (*comparisons) = (*comparisons) + 1;

    while (p != NULL) {
        (*comparisons) = (*comparisons) + 2;

        if (areTypesEqual(p->info, value)) {
            return i;
        }

        (*arithmetic) = (*arithmetic) + 1;
        p = p->next;
        i++;
    }

    return -1;
}

RUNTIME_TYPE getWorstCaseList(ListNode *node) {
    while (node->next != NULL) {
        node = node->next;
    }

    return node->info;
}

RUNTIME_TYPE getBestCaseList(ListNode *node) {
    return node->info;
}

RUNTIME_TYPE getAvgCaseList(ListNode *node) {
    int count = countListElements(node) / 2;
    int i = 0;

    while (node->next != NULL && (i++) != count) {
        node = node->next;
    }

    return node->info;
}