#ifndef MBL_LEXER_H
#define MBL_LEXER_H

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "logger.h"
#include "cursor.h"
#include "token.h"

token_t *lex_token (char *src, size_t len, cursor_t *crs);

token_t *lex_comment (char *src, size_t len, cursor_t *crs);

token_t *lex_alpha (char *src, size_t len, cursor_t *crs);

token_t *lex_digit (char *src, size_t len, cursor_t *crs);

token_t *lex_separator (char *src, size_t len, cursor_t *crs);

token_t *lex_file(char *src, size_t len);

#endif