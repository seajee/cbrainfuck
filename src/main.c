#include <stdio.h>
#include <stdlib.h>

#include "argv.h"
#include "util.h"
#include "compiler.h"

#define USAGE "Usage: cbf -i <input file>\n"
#define HELP \
    USAGE "\n" \
    "Options:\n" \
    "  -h         Show this message\n" \
    "  -i <file>  Input source file\n" \
    "  -o <file>  Output file\n" \
    "  -t         Transpile only to output file\n" \

#define FILE_OUT "a.out"
#define FILE_INTERMEDIATE "bf.c"

int main(int argc, char* argv[])
{
    // Parse arguments
    Arguments args;
    parse_argv(argc, argv, &args);

    if (args.help) {
        printf(HELP);
        return EXIT_SUCCESS;
    }

    if (args.input_file == NULL)
    {
        fprintf(stderr, "ERROR: No input file\n" USAGE "\n");
        return EXIT_FAILURE;
    }

    if (args.output_file == NULL) {
        args.output_file = FILE_OUT;
    }

    // Read source file
    FileReader fr = file_reader_read(args.input_file);

    if (fr.data == NULL) {
        fprintf(stderr, "ERROR: Could not read input file\n");
        return EXIT_FAILURE;
    }

    // Transpile the program
    if (transpile_program_to_file(fr.data, fr.size, FILE_INTERMEDIATE) < 0) {
        fprintf(stderr, "ERROR: Could not transpile program\n");
    }

    // Compile if transpile only flag is not present
    if (args.transpile_only) {
        return EXIT_SUCCESS;
    }

    if (compile_program(FILE_INTERMEDIATE, args.output_file) < 0) {
        fprintf(stderr, "ERROR: Could not compile program\n");
    }

    file_reader_free(fr);

    return EXIT_SUCCESS;
}
