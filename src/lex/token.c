#include <mbl/lex/token.h>

const char KEYWORDS[][4] = {
    "fun",
    "ret",
    "int",
    "var"
};

const size_t KEYWORDS_CNT = sizeof(KEYWORDS) / sizeof(KEYWORDS[0]);

const size_t KEYWORDS_SZ = sizeof(KEYWORDS);

Token *token_init(Cursor *crs, TokenType type) {
    Token *token = (Token *) malloc(sizeof(Token));
    token->type = type;
    token->pos = crs->pos;
    token->row = crs->row;
    token->col = crs->col;
    token->len = 1;
    token->next = NULL;
    return token;
}