#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "compiler.h"

#define FILE_OUT "a.out"
#define FILE_INTERMEDIATE "bf.c"

int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        fprintf(stderr, "Usage: cbrainfuck <filename>\n");
        return EXIT_FAILURE;
    }

    const char* src_path = argv[1];

    FileReader fr = file_reader_read(src_path);

    if (fr.data < 0) {
        fprintf(stderr, "ERROR: Could not read file\n");
        return EXIT_FAILURE;
    }

    if (transpile_program_to_file(fr.data, fr.size, FILE_INTERMEDIATE) < 0) {
        fprintf(stderr, "ERROR: Could not transpile program\n");
    }

    if (compile_program(FILE_INTERMEDIATE, FILE_OUT) < 0) {
        fprintf(stderr, "ERROR: Could not compile program\n");
    }

    file_reader_free(fr);

    return EXIT_SUCCESS;
}
