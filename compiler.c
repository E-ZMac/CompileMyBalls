#include "compiler.h"

int compileFile(const char* fileName, const char* outFileName, int flags) {
    struct compileProcess* process = compileProcessCreate(fileName, outFileName, flags);
    if (!process)
        return COMPILER_FAILED_WITH_ERRORS;
    
    // Perform lexical analysis

    // Perform parsing

    // Perform code generation

    return COMPILER_FILE_COMPILED_OK;
}