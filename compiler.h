#ifndef COMPILEMYBALLS_H
#define COMPILEMYBALLS_H

#include <stdio.h>
#include <stdbool.h>

enum {
    TOKEN_TYPE_IDENTIFIER,
    TOKEN_TYPE_KEYWORD,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_SYMBOL,
    TOKEN_TYPE_NUMBER,
    TOKEN_TYPE_STRING,
    TOKEN_TYPE_COMMENT,
    TOKEN_TYPE_NEWLINE
};
struct token {
    int type;
    int flags;

    union {
        char cval;
        const char* sval;
        unsigned int inum;
        unsigned long lnum;
        unsigned long long llnum;
        void* any;
    };

    bool whitespace;

    const char* betweenBrackets;
};

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