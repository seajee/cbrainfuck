#include "util.h"

#include <stdio.h>
#include <stdlib.h>

File* file_read(const char* file_path)
{
    FILE* file = fopen(file_path, "rb");

    if (file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char* content = (char*)malloc(file_size + 1);

    if (content == NULL) {
        return NULL;
    }

    fread(content, file_size, 1, file);
    fclose(file);

    content[file_size] = 0;

    File* result = (File*)malloc(sizeof(File));

    result->data = content;
    result->size = file_size;

    if (result == NULL) {
        return NULL;
    }

    return result;
}

void file_free(File* file)
{
    free((void*)file->data);
    free((void*)file);
}
