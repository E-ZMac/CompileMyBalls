#ifndef COMPILEMYBALLS_H
#define COMPILEMYBALLS_H

#include <stdio.h>

enum {
    COMPILER_FILE_COMPILED_OK,
    COMPILER_FAILED_WITH_ERRORS
};

struct compileProcess {
    // The flags regarding how this file should compile
    int flags;

    struct compileProcessInputFile {
        FILE* fp;
        const char* abs_path;
    } cfile;

    FILE* oFile;
};

int compileFile(const char* fileName, const char* outFileName, int flags);
struct compileProcess* compileProcessCreate(const char* fileName, const char* fileNameOut, int flags);

#endif