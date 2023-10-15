#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

FileReader file_reader_read(const char* file_path)
{
    FileReader fr = {
        .data = NULL,
        .size = -1
    };

    FILE* file = fopen(file_path, "rb");

    if (file == NULL) {
        return fr;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate memory for file content
    char* content = (char*)malloc(file_size + 1);

    if (content == NULL) {
        return fr;
    }

    // Read file content and close it
    fread(content, file_size, 1, file);
    fclose(file);

    content[file_size] = 0;

    fr.data = content;
    fr.size = file_size;

    return fr;
}

void file_reader_free(FileReader fr)
{
    free((void*)fr.data);
}

char* concat(size_t count, ...)
{
    va_list ap;

    // Find required length to store merged string
    int len = 1; // room for NULL
    va_start(ap, count);
    for(size_t i = 0; i < count; ++i) {
        len += strlen(va_arg(ap, char*));
    }
    va_end(ap);

    // Allocate memory to concat strings
    char *merged = calloc(sizeof(char),len);
    int null_pos = 0;

    // Actually concatenate strings
    va_start(ap, count);
    for(size_t i = 0; i < count; ++i)
    {
        char *s = va_arg(ap, char*);
        strcpy(merged+null_pos, s);
        null_pos += strlen(s);
    }
    va_end(ap);

    return merged;
}
