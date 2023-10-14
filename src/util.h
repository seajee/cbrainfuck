#ifndef _UTIL_H_
#define _UTIL_H_

#include <stddef.h>

typedef struct
{
    const char* data;
    size_t size;
} FileReader;

FileReader file_reader_read(const char* file_path);
void file_reader_free(FileReader fr);

#endif // _UTIL_H_
