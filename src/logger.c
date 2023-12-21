#include <mbl/logger.h>

void syntax_error (char *src, cursor_t *crs) {
    printf("[SyntaxError] Unexpected token '%c' (%d) at %d:%d\n", src[crs->pos], src[crs->pos], crs->row, crs->col);
    exit(1);
}