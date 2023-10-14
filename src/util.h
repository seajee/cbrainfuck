#ifndef _UTIL_H_
#define _UTIL_H_

#include <stddef.h>

typedef struct
{
    const char* data;
    size_t size;
} File;

File* file_read(const char* file_path);
void file_free(File* file);

#endif // _UTIL_H_
