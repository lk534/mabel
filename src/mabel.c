#include <mbl/lexer.h>
#include <mbl/io.h>

int main (void) {
    size_t len;
    char *src = file_read("example.mbl", &len);
    if (!src) {
        return 1;
    }
    lex_file(src, len);
    return 0;
}