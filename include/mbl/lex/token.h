#ifndef MBL_TOKEN
#define MBL_TOKEN_H

#include <stdlib.h>

#include "cursor.h"

extern const char KEYWORDS[][4];
extern const size_t KEYWORDS_CNT;
extern const size_t KEYWORDS_SZ;

typedef enum {
    TK_NUL,
    TK_EOF,
    // General
    TK_COM,
    TK_IDN,
    // Keywords
    TK_FUN,
    TK_RET,
    TK_INT,
    TK_VAR,
    // Literals
    TK_NUM,
    // Operators
    TK_EQUALS,
    // Separators
    TK_LPAREN,
    TK_RPAREN,
    TK_LBRACE,
    TK_RBRACE,
    TK_SEMI,
    TK_COLON
} TokenType;

typedef struct _token {
    TokenType type;
    struct _token *next;
    size_t pos;
    size_t row;
    size_t col;
    size_t len;
    int ival;
} Token;

Token *token_init(Cursor *crs, TokenType type);

#endif