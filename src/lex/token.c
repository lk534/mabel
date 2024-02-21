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

TokenGroup token_group(TokenType type) {
    switch (type) {
    case TK_EOF:
    case TK_COM:
    case TK_IDN:
        return TKG_GENERAL;
    case TK_FUN:
    case TK_RET:
    case TK_INT:
    case TK_VAR:
        return TKG_KEYWORDS;
    case TK_NUM:
        return TKG_LITERALS;
    case TK_EQUALS:
        return TKG_OPERATORS;
    case TK_LPAREN:
    case TK_RPAREN:
    case TK_LBRACE:
    case TK_RBRACE:
    case TK_SEMI:
    case TK_COLON:
        return TKG_SEPERATORS;
    case TK_NUL:
    default:
        // TODO: Throw error here.
        return TKG_NUL;
    }
}