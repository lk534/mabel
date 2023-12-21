#ifndef MBL_LOGGER_H
#define MBL_LOGGER_H

#include <stdlib.h>
#include <stdio.h>

#include "lex/cursor.h"

void syntax_error (char *src, cursor_t *crs);

#endif