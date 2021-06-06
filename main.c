#include <stdio.h>
#include <conio.h>

#include "file.h"

#include "time/array_time.h"

void runTest(TestType type, const char *fileType, int n);
void askForCase(TestType type, const char *fileType);
void askForFileType(TestType type);
void askForDataStructure();

void runTest(TestType type, const char *fileType, int n) {
    switch (n) {
        case 1: {
            RUNTIME_TYPE element;

            if (strcmp(fileType, STR_FILE) == 0) {
                element = createString("abcdefghijklmn");
            } else {
                element = createNumber(5260);
            }

            worstCaseTest(type, fileType, element);
            break;
        }
        case 2: {
            RUNTIME_TYPE element;

            if (strcmp(fileType, STR_FILE) == 0) {
                element = createString("aaa");
            } else {
                element = createNumber(597);
            }

            bestCaseTest(type, fileType, element);
            break;
        }
        case 3: {
            avgCaseTest(type, fileType);
            break;
        }
        case 4: {
            askForFileType(type);
            return;
        }
    }

    printf("Press any key to go back to the main menu...\n");
    getch();
    askForDataStructure();
}

void askForCase(TestType type, const char *fileType) {
    system("cls");
    printf("STRUCTURE TESTER\n");
    printf("================\n");
    printf("Which case would you like to test?\n\n");
    printf("1. Worst Case\n");
    printf("2. Best Case\n");
    printf("3. Average Case\n");
    printf("4. Back\n\n>> ");

    int n;
    scanf("%i", &n);

    runTest(type, fileType, n);
}

void askForFileType(TestType type) {
    system("cls");
    printf("STRUCTURE TESTER\n");
    printf("================\n");
    printf("Which file type would you like to test with?\n\n");
    printf("1. Numbers only\n");
    printf("2. Strings only\n");
    printf("3. Numbers and strings, combined\n");
    printf("4. Back\n\n>> ");

    int n;
    scanf("%i", &n);

    switch (n) {
        case 1:
            askForCase(type, INT_FILE);
            break;
        case 2:
            askForCase(type, STR_FILE);
            break;
        case 3:
            askForCase(type, COMBINED_FILE);
            break;
        default:
            askForDataStructure();
            break;
    }
}

void askForDataStructure() {
    system("cls");
    printf("STRUCTURE TESTER\n");
    printf("================\n");
    printf("Which data structure would you like to test?\n\n");
    printf("0. None, please regenerate test files\n");
    printf("1. Array\n");
    printf("2. Dynamic List\n");
    printf("3. Binary Tree\n");
    printf("4. Heap\n");
    printf("5. Hash Table\n");
    printf("6. Exit\n\n>> ");

    int n;
    scanf("%i", &n);

    switch (n) {
        case 0: {
            generateAllFiles();
            system("cls");
            printf("Test files have been regenerated!\nPress any key to continue...\n");
            getch();
            askForDataStructure();
            break;
        }
        case 6:
            exit(0);
            break;
        default:
            if (n > 6) {
                askForDataStructure();
                break;
            }

            askForFileType(n - 1);
            break;
    }
}

int main() {
    srand(time(0));

    generateAllFiles();
    askForDataStructure();

    return 0;
}
