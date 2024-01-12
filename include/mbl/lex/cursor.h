#ifndef MBL_CURSOR_H
#define MBL_CURSOR_H

#include <stddef.h>

typedef struct {
    size_t pos;
    size_t row;
    size_t col;
} Cursor;

void cursor_advance (char *src, Cursor *crs);

#endif