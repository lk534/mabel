#include <mbl/lex/lexer.h>
#include <mbl/io.h>

int main (void) {
    string_t str = file_read("example.mbl");
    if (!str.src) {
        return 1;
    }
    lex_file(str.src, str.len);
    return 0;
}