#include <stdio.h>
#include <stdlib.h>
#include "compiler.h"

struct compileProcess* compileProcessCreate(const char* fileName, const char* fileNameOut, int flags) {
    FILE* file = fopen(fileName, "r");
    if (!file) {
        return NULL;
    }

    FILE* outFile = NULL;
    if (fileNameOut) {
        outFile = fopen(fileNameOut, "w");
        if (!outFile) {
            return NULL;
        }
    }

    struct compileProcess* process = calloc(1, sizeof(struct compileProcess));
    process->flags = flags;
    process->cfile.fp = file;
    process->oFile = outFile;
    return process;
}