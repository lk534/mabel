#ifndef MBL_TOKEN
#define MBL_TOKEN_H

#include <stdlib.h>

#include "cursor.h"

extern const char KEYWORDS[][4];
extern const size_t KEYWORDS_CNT;
extern const size_t KEYWORDS_SZ;

typedef enum {
    // General
    TK_COM,
    TK_IDN,
    // Keywords
    KW_FUN,
    KW_RET,
    KW_INT,
    // Literals
    LT_INT,
    // Separators
    SP_LPAREN,
    SP_RPAREN,
    SP_LBRACE,
    SP_RBRACE,
    SP_SEMI,
    SP_COLON
} toktype_e;

typedef struct _token {
    toktype_e type;
    struct _token *next;
    size_t pos;
    size_t row;
    size_t col;
    size_t len;
    int ival;
} token_t;

token_t *token_init(cursor_t *crs, toktype_e type);

#endif