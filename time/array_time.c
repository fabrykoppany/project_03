//
// Created by koppa on 2021. 05. 23..
//

#include "array_time.h"

void bestCaseArray(const char *type, RUNTIME_TYPE element) {
    ARRAY array = createArray(100000);
    char *buffer = generateFileName(type, 100000);

    readArrayFromInputFile(&array, buffer);
    free(buffer);

    removeArray(&array, array.elements[0]);

    // Adding element
    clock_t start = clock();
    addArray(&array, element);
    clock_t end = clock();
    double elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Adding element - best case: %.30f\n", elapsed_time);

    // Searching element
    start = clock();
    printf(findArray(array, element) ? "The searched elements was found.\n" : "The searched elements wasn't found\n");
    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Searching element - best case (first element): %.30f\n", elapsed_time);

    // Getting element
    start = clock();
    printf("\n");
    printRuntimeType(getNthArray(array, 1));
    printf("\n");
    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Getting n^th element - best case (first element): %.30f\n", elapsed_time);

    // Removing element
    start = clock();
    removeArray(&array, element);
    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Removing element - best case (first element): %.30f\n", elapsed_time);

    destroyArray(&array);
}

void worstCaseArray(const char *type, RUNTIME_TYPE element) {
    ARRAY array = createArray(100000);
    char *buffer = generateFileName(type, 100000);

    readArrayFromInputFile(&array, buffer);
    free(buffer);

    removeArray(&array, array.elements[0]);

    // Adding element
    clock_t start = clock();
    addArray(&array, element);
    clock_t end = clock();
    double elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Adding element - worst case: %.30f\n", elapsed_time);

    // Searching element
    start = clock();
    printf(findArray(array, element) ? "The searched elements was found.\n" : "The searched elements wasn't found\n");
    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Searching element - worst case (final element): %.30f\n", elapsed_time);

    // Getting element
    start = clock();
    printf("\n");
    printRuntimeType(getNthArray(array, 100000));
    printf("\n");
    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Getting n^th element - worst case (final element): %.30f\n", elapsed_time);

    // Removing element
    start = clock();
    removeArray(&array, element);
    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Removing element - worst case (final element): %.30f\n", elapsed_time);

    destroyArray(&array);
}

void avgCaseArray(const char *type) {
    double time1, time2, time3, time4;

    time1 = time2 = time3 = time4 = 0;

    for (int i = 10; i < 1000000; i *= 10){
        char *buffer = generateFileName(type, i);

        ARRAY array = createArray(i);

        readArrayFromInputFile(&array, buffer);

        free(buffer);

        RUNTIME_TYPE num = array.elements[array.nr_elements / 2];

        // Adding element
        clock_t start = clock();
        addArray(&array, num);
        clock_t end = clock();
        time1 += (double) (end - start) / CLOCKS_PER_SEC;

        // Searching element
        start = clock();
        printf(findArray(array, num) ? "The searched elements was found.\n" : "The searched elements wasn't found\n");
        end = clock();
        time2 += (double) (end - start) / CLOCKS_PER_SEC;

        // Getting element
        start = clock();
        printf("\n");
        printRuntimeType(getNthArray(array, array.nr_elements / 2));
        printf("\n");
        end = clock();
        time3 += (double) (end - start) / CLOCKS_PER_SEC;

        // Removing element
        start = clock();
        removeArray(&array, num);
        end = clock();
        time4 = (double) (end - start) / CLOCKS_PER_SEC;

        destroyArray(&array);
    }

    printf("Adding element - average case: %.30f\n", time1 / 5);
    printf("Searching element - average case: %.30f\n", time2 / 5);
    printf("Getting n^th element - average case: %.30f\n", time3 / 5);
    printf("Removing element - average case: %.30f\n", time4 / 5);
}