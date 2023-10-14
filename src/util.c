#include "util.h"

#include <stdio.h>
#include <stdlib.h>

FileReader file_reader_read(const char* file_path)
{
    FileReader fr = {
        .data = (char*)(-1),
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
