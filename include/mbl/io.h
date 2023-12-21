#ifndef MBL_IO_H
#define MBL_IO_H

#include <stdlib.h>
#include <stdio.h>

char *file_read (const char *path, size_t *len);

char file_write (const char *path, const char *src, const size_t len);

#endif