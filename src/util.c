#include "util.h"

#include <stdio.h>
#include <stdlib.h>

const char* read_file(const char* file_path)
{
    FILE* file = fopen(file_path, "rb");

    if (file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char* content = malloc(file_size + 1);

    if (content == NULL) {
        return NULL;
    }

    fread(content, file_size, 1, file);
    fclose(file);

    content[file_size] = 0;

    return content;
}
