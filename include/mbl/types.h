#ifndef MBL_TYPES_H
#define MBL_TYPES_H

#include <stddef.h>

typedef struct {
    char *src;
    size_t len;
} string_t;

extern const string_t nullstr;

typedef unsigned char byte_t;

#endif