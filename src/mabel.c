#include <mbl/lex/lexer.h>
#include <mbl/logger.h>
#include <mbl/io.h>

int main (int argc, char *argv[]) {
    if (argc < 2) {
        MBL_TRM("Provide input file...");
    }
    MBL_INF("Compiling %s...", argv[1]);
    
    string_t str = file_read(argv[1]);
    if (!str.src) {
        return 1;
    }

    MBL_DBG("Lexing...");
    lex_file(str.src, str.len);

    MBL_INF("Done.");
    return 0;
}