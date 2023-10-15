#include "argv.h"

#include <unistd.h>

void parse_argv(int argc, char** argv, Arguments* args)
{
    args->help = false;
    args->input_file = NULL;
    args->output_file = NULL;
    args->transpile_only = false;

    int opt;

    while ((opt = getopt(argc, argv, "i:o:th")) != -1) {
        switch (opt) {
            case 'h':
                args->help = true;
                return;
            case 'i':
                args->input_file = optarg;
                break;
            case 'o':
                args->output_file = optarg;
                break;
            case 't':
                args->transpile_only = true;
                break;
        }
    }
}
