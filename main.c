#include <stdio.h>
#include "helpers/vector.h"
#include "compiler.h"

int main() {
    int res = compileFile("./test.c", "./test", 0);
    if (res == COMPILER_FILE_COMPILED_OK) {
        printf("Compile completed with no errors\n");
    } else if (res == COMPILER_FAILED_WITH_ERRORS) {
        printf("Compile failed\n");
    } else {
        printf("Unkown response for compile file");
    }

    return 0;
}