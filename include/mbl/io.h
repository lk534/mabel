#ifndef MBL_IO_H
#define MBL_IO_H

#include <stdlib.h>
#include <stdio.h>

#include "types.h"

string_t file_read (const char *path);

char file_write (const char *path, const string_t str);

#endif