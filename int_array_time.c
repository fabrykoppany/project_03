//
// Created by koppa on 2021. 05. 23..
//

#include "int_array_time.h"

void bestCaseIntArray(){
    INT_ARRAY array = createIntArray(100000);

    readIntArrayFromInputFile(&array, "int100000.txt");

    int num = 597;

    removeIntArray(&array, array.elements[0]);

    // Adding element
    clock_t start = clock();
    addIntArray(&array, num);
    clock_t end = clock();
    double elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Adding element - best case: %.30f\n", elapsed_time);

    // Searching element
    start = clock();
    printf(findIntArray(array, num) ? "The searched elements was found.\n" : "The searched elements wasn't found\n");
    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Searching element - best case (first element): %.30f\n", elapsed_time);

    // Getting element
    start = clock();
    printf("\n%i\n", getNthIntArray(array, 1));
    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Getting n^th element - best case (first element): %.30f\n", elapsed_time);

    // Removing element
    start = clock();
    removeIntArray(&array, num);
    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Removing element - best case (first element): %.30f\n", elapsed_time);

    destroyIntArray(&array);

}

void worstCaseIntArray(){
    INT_ARRAY array = createIntArray(100000);

    readIntArrayFromInputFile(&array, "int100000.txt");

    int num = 5260;

    removeIntArray(&array, array.elements[0]);

    // Adding element
    clock_t start = clock();
    addIntArray(&array, num);
    clock_t end = clock();
    double elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Adding element - worst case: %.30f\n", elapsed_time);

    // Searching element
    start = clock();
    printf(findIntArray(array, num) ? "The searched elements was found.\n" : "The searched elements wasn't found\n");
    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Searching element - worst case (final element): %.30f\n", elapsed_time);

    // Getting element
    start = clock();
    printf("\n%i\n", getNthIntArray(array, 100000));
    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Getting n^th element - worst case (final element): %.30f\n", elapsed_time);

    // Removing element
    start = clock();
    removeIntArray(&array, num);
    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Removing element - worst case (final element): %.30f\n", elapsed_time);
}

void avgCaseIntArray(){
    double time1, time2, time3, time4;

    time1 = time2 = time3 = time4 = 0;

    for (int i = 10; i < 1000000; i *= 10){
        char *buffer = generateFileName("int", i);

        INT_ARRAY array = createIntArray(i);

        readIntArrayFromInputFile(&array, buffer);

        int num = array.elements[array.nr_elements / 2];

        // Adding element
        clock_t start = clock();
        addIntArray(&array, num);
        clock_t end = clock();
        time1 += (double) (end - start) / CLOCKS_PER_SEC;

        // Searching element
        start = clock();
        printf(findIntArray(array, num) ? "The searched elements was found.\n" : "The searched elements wasn't found\n");
        end = clock();
        time2 += (double) (end - start) / CLOCKS_PER_SEC;

        // Getting element
        start = clock();
        printf("\n%i\n", getNthIntArray(array, array.nr_elements / 2));
        end = clock();
        time3 += (double) (end - start) / CLOCKS_PER_SEC;

        // Removing element
        start = clock();
        removeIntArray(&array, num);
        end = clock();
        time4 = (double) (end - start) / CLOCKS_PER_SEC;
    }

    printf("Adding element - average case: %.30f\n", time1 / 5);
    printf("Searching element - average case: %.30f\n", time2 / 5);
    printf("Getting n^th element - average case: %.30f\n", time3 / 5);
    printf("Removing element - average case: %.30f\n", time4 / 5);
}