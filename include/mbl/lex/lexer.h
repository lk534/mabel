#ifndef MBL_LEXER_H
#define MBL_LEXER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "../logger.h"
#include "cursor.h"
#include "token.h"

Token *lex_token (char *src, size_t len, Cursor *crs);

Token *lex_comment (char *src, size_t len, Cursor *crs);

Token *lex_alpha (char *src, size_t len, Cursor *crs);

Token *lex_digit (char *src, size_t len, Cursor *crs);

Token *lex_single (char *src, size_t len, Cursor *crs);

Token *lex_file(char *src, size_t len);

#endif