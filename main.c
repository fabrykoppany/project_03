#include <stdio.h>

#include "file.h"

#include "time/array_time.h"

int main() {

    srand(time(0));

    generateAllFiles();
    worstCaseArray("int", createNumber(5260));
    bestCaseArray("int", createNumber(597));
    avgCaseArray("combined");

    return 0;
}
