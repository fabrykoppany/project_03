#include "array_time.h"

void bestCaseTest(TestType test, const char *type, RUNTIME_TYPE element) {
    ARRAY array;
    ListNode *head = NULL;
    TreeNode *tree = NULL;
    HashTable *table = NULL;
    Heap *heap = NULL;

    switch (test) {
        case TEST_ARRAY:
            array = createArray(100000);
            break;
        case TEST_LIST:
            head = createListNode();
            break;
        case TEST_BTREE:
            break;
        case TEST_HASHTABLE:
            table = allocateHashTable(100000);
            break;
        case TEST_HEAP:
            heap = createHeap(100000);
            break;
    }

    int comparisons = 0;
    int arithmetic = 0;

    // Next, read the test file according to the test type
    char *buffer = generateFileName(type, 100000);

    switch (test) {
        case TEST_ARRAY:
            readArrayFromInputFile(&array, buffer, &comparisons, &arithmetic);
            break;
        case TEST_LIST:
            readListFromInputFile(&head, buffer, &comparisons);
            break;
        case TEST_BTREE:
            tree = readBtreeFromInputFile(tree, buffer, &comparisons, &arithmetic);
            break;
        case TEST_HASHTABLE:
            readTableFromInputFile(table, buffer, &comparisons, &arithmetic);
            break;
        case TEST_HEAP:
            readHeapFromInputFile(heap, buffer, &comparisons, &arithmetic);
            break;
    }

    printf("Creating structure took %d comparisons and %d arithmetic operations\n", comparisons, arithmetic);
    free(buffer);

    comparisons = 0;
    arithmetic = 0;

    switch (test) {
        case TEST_ARRAY:
            removeArray(&array, getBestCaseArray(&array), &comparisons, &arithmetic);
            break;
        case TEST_LIST:
            deleteListNode(&head, getBestCaseList(head), &comparisons);
            break;
        case TEST_BTREE:
            tree = deleteNode(tree, getBestCaseBtree(tree), &comparisons);
            break;
        case TEST_HASHTABLE:
            removeHashTable(table, getBestCaseTable(table), &comparisons, &arithmetic);
            break;
        case TEST_HEAP:
            break;
    }

    printf("Removing element took %d comparisons and %d arithmetic operations\n", comparisons, arithmetic);

    comparisons = 0;
    arithmetic = 0;

    // Adding element
    clock_t start = clock();

    switch (test) {
        case TEST_ARRAY:
            addArray(&array, element, &comparisons, &arithmetic);
            break;
        case TEST_LIST:
            appendListNode(&head, element, &comparisons);
            break;
        case TEST_BTREE:
            tree = insertNode(tree, element, &comparisons, &arithmetic);
            break;
        case TEST_HASHTABLE:
            insertHashTable(table, element, &comparisons, &arithmetic);
            break;
        case TEST_HEAP:
            insertHeap(heap, element, &comparisons, &arithmetic);
            break;
    }

    clock_t end = clock();
    double elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Adding element - best case: %.30f\n", elapsed_time);

    // Searching element
    comparisons = 0;
    arithmetic = 0;
    bool found = false;

    start = clock();

    switch (test) {
        case TEST_ARRAY:
            found = findArray(array, element, &comparisons, &arithmetic);
            break;
        case TEST_LIST:
            found = findElementInList(head, element, &comparisons, &arithmetic);
            break;
        case TEST_BTREE:
            if (searchTree(tree, element, &comparisons, &arithmetic) == NULL){
                found = false;
            }
            else found = true;
            comparisons++;
            break;
        case TEST_HASHTABLE:
            found = findHashTable(table, element, &comparisons, &arithmetic) != -1;
            comparisons++;
            break;
        case TEST_HEAP:
            found = getHeapIndex(heap, element, &comparisons, &arithmetic) != -1;
            comparisons++;
            break;
    }

    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf(found ? "The searched element was found.\n" : "The searched element wasn't found\n");
    printf("Searching element took %d comparisons and %d arithmetic operations\n", comparisons, arithmetic);
    printf("Searching element - best case (first element): %.30f\n", elapsed_time);

    // Getting element
    comparisons = 0;
    arithmetic = 0;
    start = clock();
    RUNTIME_TYPE bestElement;

    switch (test) {
        case TEST_ARRAY:
            bestElement = getBestCaseArray(&array);
            break;
        case TEST_LIST:
            bestElement = getBestCaseList(head);
            break;
        case TEST_BTREE:
            bestElement = getBestCaseBtree(tree);
            break;
        case TEST_HASHTABLE:
            bestElement = getBestCaseTable(table);
            break;
        case TEST_HEAP:
            bestElement = getBestCaseHeap(heap);
            break;
    }

    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;

    printf("\n");
    printRuntimeType(bestElement);
    printf("\n");
    printf("Getting n^th element - best case (first element): %.30f\n", elapsed_time);
    printf("Getting n^th element took %d comparisons and %d arithmetic operations\n", comparisons, arithmetic);

    // Removing element
    comparisons = 0;
    arithmetic = 0;
    start = clock();

    switch (test) {
        case TEST_ARRAY:
            removeArray(&array, bestElement, &comparisons, &arithmetic);
            break;
        case TEST_LIST:
            deleteListNode(&head, bestElement, &comparisons);
            break;
        case TEST_BTREE:
            tree = deleteNode(tree, bestElement, &comparisons);
            break;
        case TEST_HASHTABLE:
            removeHashTable(table, bestElement, &comparisons, &arithmetic);
            break;
        case TEST_HEAP:
            break;
    }

    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Removing element - best case (first element): %.30f\n", elapsed_time);
    printf("Removing element took %d comparisons and %d arithmetic operations\n", comparisons, arithmetic);

    switch (test) {
        case TEST_ARRAY:
            destroyArray(&array);
            break;
        case TEST_LIST:
            freeList(&head);
            break;
        case TEST_BTREE:
            freeTree(tree);
            break;
        case TEST_HASHTABLE:
            freeHashTable(table);
            break;
        case TEST_HEAP:
            freeHeap(heap);
            break;
    }
}

void worstCaseTest(TestType test, const char *type, RUNTIME_TYPE element) {
    ARRAY array;
    ListNode *head = NULL;
    TreeNode *tree = NULL;
    HashTable *table = NULL;
    Heap *heap = NULL;

    switch (test) {
        case TEST_ARRAY:
            array = createArray(100000);
            break;
        case TEST_LIST:
            head = createListNode();
            break;
        case TEST_BTREE:
            break;
        case TEST_HASHTABLE:
            table = allocateHashTable(100000);
            break;
        case TEST_HEAP:
            heap = createHeap(100000);
            break;
    }

    char *buffer = generateFileName(type, 100000);

    int comparisons = 0;
    int arithmetic = 0;

    switch (test) {
        case TEST_ARRAY:
            readArrayFromInputFile(&array, buffer, &comparisons, &arithmetic);
            break;
        case TEST_LIST:
            readListFromInputFile(&head, buffer, &comparisons);
            break;
        case TEST_BTREE:
            tree = readBtreeFromInputFile(tree, buffer, &comparisons, &arithmetic);
            break;
        case TEST_HASHTABLE:
            readTableFromInputFile(table, buffer, &comparisons, &arithmetic);
            break;
        case TEST_HEAP:
            readHeapFromInputFile(heap, buffer, &comparisons, &arithmetic);
            break;
    }

    printf("Creating structure took %d comparisons and %d arithmetic operations\n", comparisons, arithmetic);
    free(buffer);

    comparisons = 0;
    arithmetic = 0;

    int level = height(tree);

    switch (test) {
        case TEST_ARRAY:
            removeArray(&array, getWorstCaseArray(&array), &comparisons, &arithmetic);
            break;
        case TEST_LIST:
            deleteListNode(&head, getWorstCaseList(head), &comparisons);
            break;
        case TEST_BTREE:
            tree = deleteNode(tree, getWorstCaseBtree(tree, level), &comparisons);
            break;
        case TEST_HASHTABLE:
            removeHashTable(table, getWorstCaseTable(table), &comparisons, &arithmetic);
            break;
        case TEST_HEAP:
            break;
    }

    printf("Removing element took %d comparisons and %d arithmetic operations\n", comparisons, arithmetic);

    // Adding element
    clock_t start = clock();

    switch (test) {
        case TEST_ARRAY:
            addArray(&array, element, &comparisons, &arithmetic);
            break;
        case TEST_LIST:
            appendListNode(&head, element, &comparisons);
            break;
        case TEST_BTREE:
            tree = insertNode(tree, element, &comparisons, &arithmetic);
            break;
        case TEST_HASHTABLE:
            insertHashTable(table, element, &comparisons, &arithmetic);
            break;
        case TEST_HEAP:
            insertHeap(heap, element, &comparisons, &arithmetic);
            break;
    }

    clock_t end = clock();
    double elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Adding element - worst case: %.30f\n", elapsed_time);
    printf("Adding element took %d comparisons and %d arithmetic operations\n", comparisons, arithmetic);

    // Searching element
    comparisons = 0;
    arithmetic = 0;
    bool found = false;

    start = clock();

    switch (test) {
        case TEST_ARRAY:
            found = findArray(array, element, &comparisons, &arithmetic);
            break;
        case TEST_LIST:
            found = findElementInList(head, element, &comparisons, &arithmetic);
            break;
        case TEST_BTREE:
            if (searchTree(tree, element, &comparisons, &arithmetic) == NULL) {
                found = false;
            } else found = true;
            comparisons++;
            break;
        case TEST_HASHTABLE:
            found = findHashTable(table, element, &comparisons, &arithmetic) != -1;
            comparisons++;
            break;
        case TEST_HEAP:
            found = getHeapIndex(heap, element, &comparisons, &arithmetic) != -1;
            comparisons++;
            break;
    }

    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf(found ? "The searched element was found.\n" : "The searched element wasn't found\n");
    printf("Searching element - worst case (final element): %.30f\n", elapsed_time);

    // Getting element
    comparisons = 0;
    arithmetic = 0;
    start = clock();
    RUNTIME_TYPE worstElement;

    switch (test) {
        case TEST_ARRAY:
            worstElement = getWorstCaseArray(&array);
            break;
        case TEST_LIST:
            worstElement = getWorstCaseList(head);
            break;
        case TEST_BTREE:
            level = height(tree);
            worstElement = getWorstCaseBtree(tree, level);
            break;
        case TEST_HASHTABLE:
            worstElement = getWorstCaseTable(table);
            break;
        case TEST_HEAP:
            worstElement = getWorstCaseHeap(heap);
            break;
    }

    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;

    printf("Getting n^th element - worst case (final element): %.30f\n", elapsed_time);

    // Removing element
    comparisons = 0;
    arithmetic = 0;
    start = clock();

    switch (test) {
        case TEST_ARRAY:
            removeArray(&array, worstElement, &comparisons, &arithmetic);
            break;
        case TEST_LIST:
            deleteListNode(&head, worstElement, &comparisons);
            break;
        case TEST_BTREE:
            tree = deleteNode(tree, worstElement, &comparisons);
            break;
        case TEST_HASHTABLE:
            removeHashTable(table, worstElement, &comparisons, &arithmetic);
            break;
        case TEST_HEAP:
            break;
    }

    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Removing element - worst case (final element): %.30f\n", elapsed_time);
    printf("Removing element took %d comparisons and %d arithmetic operations\n", comparisons, arithmetic);

    switch (test) {
        case TEST_ARRAY:
            destroyArray(&array);
            break;
        case TEST_LIST:
            freeList(&head);
            break;
        case TEST_BTREE:
            freeTree(tree);
            break;
        case TEST_HASHTABLE:
            freeHashTable(table);
            break;
        case TEST_HEAP:
            freeHeap(heap);
            break;
    }
}

void avgCaseTest(TestType test, const char *type) {
    double time0, time1, time2, time3, time4;

    time0 = time1 = time2 = time3 = time4 = 0;

    for (int i = 10; i < 1000000; i *= 10){
        char *buffer = generateFileName(type, i);

        ARRAY array;
        ListNode *head = NULL;
        TreeNode *tree = NULL;
        HashTable *table = NULL;
        Heap *heap = NULL;

        switch (test) {
            case TEST_ARRAY:
                array = createArray(i);
                break;
            case TEST_LIST:
                head = createListNode();
                break;
            case TEST_BTREE:
                break;
            case TEST_HASHTABLE:
                table = allocateHashTable(100000);
                break;
            case TEST_HEAP:
                heap = createHeap(100000);
                break;
        }

        int comparisons = 0;
        int arithmetic = 0;

        switch (test) {
            case TEST_ARRAY:
                readArrayFromInputFile(&array, buffer, &comparisons, &arithmetic);
                break;
            case TEST_LIST:
                readListFromInputFile(&head, buffer, &comparisons);
                break;
            case TEST_BTREE:
                tree = readBtreeFromInputFile(tree, buffer, &comparisons, &arithmetic);
                break;
            case TEST_HASHTABLE:
                readTableFromInputFile(table, buffer, &comparisons, &arithmetic);
                break;
            case TEST_HEAP:
                readHeapFromInputFile(heap, buffer, &comparisons, &arithmetic);
                break;
        }

        free(buffer);
        printf("Creating structure took %d comparisons and %d arithmetic operations\n", comparisons, arithmetic);

        RUNTIME_TYPE num;

        int level;

        switch (test) {
            case TEST_ARRAY:
                num = getWorstCaseArray(&array);
                break;
            case TEST_LIST:
                num = getWorstCaseList(head);
                break;
            case TEST_BTREE:
                level = height(tree);
                num = getWorstCaseBtree(tree, level);
                break;
            case TEST_HASHTABLE:
                num = getWorstCaseTable(table);
                break;
            case TEST_HEAP:
                num = getWorstCaseHeap(heap);
                break;
        }

        // Adding element
        comparisons = 0;
        arithmetic = 0;
        clock_t start = clock();

        switch (test) {
            case TEST_ARRAY:
                addArray(&array, num, &comparisons, &arithmetic);
                break;
            case TEST_LIST:
                appendListNode(&head, num, &comparisons);
                break;
            case TEST_BTREE:
                tree = insertNode(tree, num, &comparisons, &arithmetic);
                break;
            case TEST_HASHTABLE:
                insertHashTable(table, num, &comparisons, &arithmetic);
                break;
            case TEST_HEAP:
                insertHeap(heap, num, &comparisons, &arithmetic);
                break;
        }

        clock_t end = clock();
        time1 += (double) (end - start) / CLOCKS_PER_SEC;
        printf("Adding element took %d comparisons and %d arithmetic operations\n", comparisons, arithmetic);

        // Searching element
        comparisons = 0;
        arithmetic = 0;
        bool found = false;

        start = clock();

        switch (test) {
            case TEST_ARRAY:
                found = findArray(array, num, &comparisons, &arithmetic);
                break;
            case TEST_LIST:
                found = findElementInList(head, num, &comparisons, &arithmetic);
                break;
            case TEST_BTREE:
                if (searchTree(tree, num, &comparisons, &arithmetic) == NULL){
                    found = false;
                }
                else found = true;
                comparisons++;
                break;
            case TEST_HASHTABLE:
                found = findHashTable(table, num, &comparisons, &arithmetic) != -1;
                comparisons++;
                break;
            case TEST_HEAP:
                found = getHeapIndex(heap, num, &comparisons, &arithmetic) != -1;
                comparisons++;
                break;
        }

        end = clock();
        printf(found ? "The searched element was found.\n" : "The searched element wasn't found\n");
        time2 += (double) (end - start) / CLOCKS_PER_SEC;

        // Getting element
        comparisons = 0;
        arithmetic = 0;
        start = clock();
        RUNTIME_TYPE avgElement;

        switch (test) {
            case TEST_ARRAY:
                avgElement = getAvgCaseArray(&array);
                break;
            case TEST_LIST:
                avgElement = getAvgCaseList(head);
                break;
            case TEST_BTREE:
                level = height(tree) / 2;
                avgElement = getAvgCaseBtree(tree, level);
                break;
            case TEST_HASHTABLE:
                avgElement = getAvgCaseTable(table);
                break;
            case TEST_HEAP:
                avgElement = getAvgCaseHeap(heap);
                break;
        }

        end = clock();

        printf("\n");
        printRuntimeType(avgElement);
        printf("\n");
        end = clock();
        time3 += (double) (end - start) / CLOCKS_PER_SEC;

        // Removing element
        comparisons = 0;
        arithmetic = 0;
        start = clock();

        switch (test) {
            case TEST_ARRAY:
                removeArray(&array, avgElement, &comparisons, &arithmetic);
                break;
            case TEST_LIST:
                deleteListNode(&head, avgElement, &comparisons);
                break;
            case TEST_BTREE:
                tree = deleteNode(tree, avgElement, &comparisons);
                break;
            case TEST_HASHTABLE:
                removeHashTable(table, avgElement, &comparisons, &arithmetic);
                break;
            case TEST_HEAP:
                break;
        }

        end = clock();
        time4 += (double) (end - start) / CLOCKS_PER_SEC;

        switch (test) {
            case TEST_ARRAY:
                destroyArray(&array);
                break;
            case TEST_LIST:
                freeList(&head);
                break;
            case TEST_BTREE:
                freeTree(tree);
                break;
            case TEST_HASHTABLE:
                freeHashTable(table);
                break;
            case TEST_HEAP:
                freeHeap(heap);
                break;
        }
    }

    printf("Creating structure - average case: %.30f\n", time0 / 5);
    printf("Adding element - average case: %.30f\n", time1 / 5);
    printf("Searching element - average case: %.30f\n", time2 / 5);
    printf("Getting n^th element - average case: %.30f\n", time3 / 5);
    printf("Removing element - average case: %.30f\n", time4 / 5);
}