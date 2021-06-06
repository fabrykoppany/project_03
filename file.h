#ifndef PROJECT_03_FILE_H
#define PROJECT_03_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INT_FILE "int"
#define STR_FILE "string"
#define COMBINED_FILE "combined"

const char *generateFileName(const char *type, int n);
void generateStringFile(int n);
void generateIntFile(int n);
void generateAllFiles();

#endif //PROJECT_03_FILE_H
