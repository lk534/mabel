#include <mbl/lex/token.h>

const char KEYWORDS[][4] = {
    "fun",
    "ret",
    "int"
};

const size_t KEYWORDS_CNT = sizeof(KEYWORDS) / sizeof(KEYWORDS[0]);

const size_t KEYWORDS_SZ = sizeof(KEYWORDS);

token_t *token_init(cursor_t *crs, toktype_e type) {
    token_t *token = (token_t *) malloc(sizeof(token_t));
    token->type = type;
    token->pos = crs->pos;
    token->row = crs->row;
    token->col = crs->col;
    token->len = 1;
    token->next = NULL;
    return token;
}