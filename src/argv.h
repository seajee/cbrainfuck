#ifndef _ARGV_H_
#define _ARGV_H_

#include <stdbool.h>

typedef struct
{
    bool help;
    const char* input_file;
    const char* output_file;
    bool transpile_only;
} Arguments;

void parse_argv(int argc, char** argv, Arguments* args);

#endif // _ARGV_H_
