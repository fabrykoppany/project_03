#include "file.h"

char *generateFileName(const char *type, int n){
    char *buffer1 = (char *) calloc(50, sizeof(char));

    if (buffer1 == NULL){
        printf("Error allocating memory for buffer!\n");
        exit(-1);
    }

    sprintf(buffer1, "%s%i.txt", type, n);

    buffer1 = realloc(buffer1, strlen(buffer1) * sizeof(char));

    return buffer1;
}

void generateStringFile(int n){
    const char *file_name = generateFileName(STR_FILE, n);
    FILE *output_file = fopen(file_name, "w");

    if (output_file == NULL){
        printf("Error opening %s", file_name);
        exit(-2);
    }

    fprintf(output_file, "%i\n", n);

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
    const char *file_name = generateFileName(INT_FILE, n);
    FILE *output_file = fopen(file_name, "w");

    if (output_file == NULL){
        printf("Error opening %s", file_name);
        exit(-2);
    }

    fprintf(output_file, "%i\n", n);

    for (int i = 0; i < n; ++i){
        int rand_num = rand() % 1000;
        fprintf(output_file, "%i\n", rand_num);
    }

    fclose(output_file);
}

void generateCombinedFile(int n){
    const char *file_name = generateFileName(COMBINED_FILE, n);
    FILE *output_file = fopen(file_name, "w");

    if (output_file == NULL){
        printf("Error opening %s", file_name);
        exit(-2);
    }

    fprintf(output_file, "%i\n", n);

    for (int i = 0; i < n; ++i){
        if (rand() & 1) {
            int rand_num = rand() % 1000;
            fprintf(output_file, "%i\n", rand_num);
        } else {
            int len = rand() % 20 + 1;

            for (int j = 0; j < len; ++j){
                char random_char = 'a' + (char) (rand() % 26);
                fprintf(output_file, "%c", random_char);
            }

            fprintf(output_file, "\n");
        }
    }

    fclose(output_file);
}

void generateAllFiles(){
    for (int i = 10; i < 1000000; i *= 10){
        generateStringFile(i);
        generateIntFile(i);
        generateCombinedFile(i);
    }
}