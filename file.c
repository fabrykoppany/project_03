//
// Created by koppa on 2021. 05. 22..
//

#include "file.h"

const char *generateFileName(const char *type, int n){
    char *buffer1 = (char *) malloc(50 * sizeof(char));
    char *buffer2 = (char *) malloc(50 * sizeof(char));

    if (buffer1 == NULL || buffer2 == NULL){
        printf("Error allocating memory for buffer!\n");
        exit(-1);
    }

    strcpy(buffer1, type);
    sprintf(buffer2, "%i", n);
    strcat(buffer1, buffer2);
    strcat(buffer1, ".txt\0");

    free(buffer2);

    buffer1 = realloc(buffer1, strlen(buffer1) * sizeof(char));

    return buffer1;
}

void generateStringFile(int n){
    const char *file_name = generateFileName("string", n);
    FILE *output_file = fopen(file_name, "w");

    if (output_file == NULL){
        printf("Error opening %s", file_name);
        exit(-2);
    }

    for (int i = 0; i < n; ++i){
        int len = rand() % 20 + 1;

        for (int j = 0; j < len; ++j){
            char random_char = 'a' + (char) (rand() % 26);
            fprintf(output_file, "%c", random_char);
        }

        fprintf(output_file, "\n");
    }

    fclose(output_file);
}

void generateIntFile(int n){
    const char *file_name = generateFileName("int", n);
    FILE *output_file = fopen(file_name, "w");

    if (output_file == NULL){
        printf("Error opening %s", file_name);
        exit(-2);
    }

    for (int i = 0; i < n; ++i){
        int rand_num = rand() % 1000;
        fprintf(output_file, "%i\n", rand_num);
    }

    fclose(output_file);
}

void generateAllFiles(){
    for (int i = 10; i < 1000000; i *= 10){
        generateStringFile(i);
        generateIntFile(i);
    }
}