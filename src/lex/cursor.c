#include <mbl/lex/cursor.h>

void cursor_advance (char *src, Cursor *crs) {
    if (src[crs->pos] == '\n') {
        crs->row++;
        crs->col = 0;
    }
    else {
        crs->col++;
    }
    crs->pos++;
}