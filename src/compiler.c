#include "compiler.h"

#include <stdio.h>
#include <stdlib.h>

#include "util.h"

int32_t transpile_program_to_file(const char* program, size_t program_size, const char* file_path)
{
    FILE* fd = fopen(file_path, "w");

    if (fd == NULL) {
        return -1;
    }

    fputs(C_ENTRYPOINT, fd);

    char inst;

    for (size_t i = 0; i < program_size; ++i)
    {
        inst = program[i];

        switch (inst)
        {
            case '>':
                fputs(C_PTR_INC, fd);
                break;
            case '<':
                fputs(C_PTR_DEC, fd);
                break;
            case '+':
                fputs(C_PLUS, fd);
                break;
            case '-':
                fputs(C_MINUS, fd);
                break;
            case '.':
                fputs(C_PRINT, fd);
                break;
            case ',':
                fputs(C_INPUT, fd);
                break;
            case '[':
                fputs(C_LOOP_START, fd);
                break;
            case ']':
                fputs(C_LOOP_END, fd);
            default:
                break;
        }
    }

    fputs(C_END, fd);

    fclose(fd);

    return 0;
}

int32_t compile_program(const char* transpiled_file_path, const char* out_file)
{
    const char* cmd = concat(5, CMD_CC, " -o ", out_file, " ", transpiled_file_path);

    int32_t status = system(cmd);
    status = remove(transpiled_file_path);

    free((void*)cmd);

    return status;
}
