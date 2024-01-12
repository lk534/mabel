#include <mbl/lex/lexer.h>

void syntax_error (char *src, cursor_t *crs) {
    printf("[SyntaxError] Unexpected character '%c' (%d) at %d:%d\n", src[crs->pos], src[crs->pos], crs->row, crs->col);
    exit(1);
}

token_t *lex_comment (char *src, size_t len, cursor_t *crs) {
    token_t *token = token_init(crs, TK_COM);

    crs->pos += 2;

    while (crs->pos < len && src[crs->pos] != '\n') crs->pos++;

    token->len = crs->pos - token->pos;
    crs->col += token->len;

    return token;
}

token_t *lex_digit (char *src, size_t len, cursor_t *crs) {
    token_t *token = token_init(crs, TK_NUM);

    // TODO: Support for HEX (0x), BIN (0b), FLOAT.
    do {
        crs->pos++;
    } while (crs->pos < len && isdigit(src[crs->pos]));

    token->len = crs->pos - token->pos;
    crs->col += token->len;

    char c = src[crs->pos+1];
    src[crs->pos+1] = '\0';
    token->ival = strtol(src+token->pos, NULL, 10);
    src[crs->pos+1] = c;

    return token;
}


token_t *lex_alpha (char *src, size_t len, cursor_t *crs) {
    token_t *token = token_init(crs, TK_IDN);

    do {
        crs->pos++;
    } while (crs->pos < len && isalnum(src[crs->pos]));

    token->len = crs->pos - token->pos;
    crs->col += token->len;
    
    // TODO: Replace KW lookup with HashTable
    const size_t kw_size = sizeof(KEYWORDS[0]);

    if (token->len < kw_size) {
        for (size_t i = 0; i < KEYWORDS_CNT; i++) {
            if (!strncmp(src + token->pos, KEYWORDS[i], token->len)) {
                token->type = TK_FUN + i;
            }
        }
    }
    return token;
}

token_t *lex_single (char *src, size_t len, cursor_t *crs) {
    toktype_e type;
    switch (src[crs->pos]) {
        case '(':
            type = TK_LPAREN;
            break;
        case ')':
            type = TK_RPAREN;
            break;
        case '{':
            type = TK_LBRACE;
            break;
        case '}':
            type = TK_RBRACE;
            break;
        case ':':
            type = TK_COLON;
            break;
        case ';':
            type = TK_SEMI;
            break;
        case '=':
            type = TK_EQUALS;
            break;
        default:
            return NULL;
    }
    token_t *token = token_init(crs, type);
    crs->pos++;
    crs->col++;
    return token;
}


token_t *lex_token (char *src, size_t len, cursor_t *crs) {
    if (!strncmp(src + crs->pos, "//", 2)) {
        return lex_comment(src, len, crs);
    }

    if (isdigit(src[crs->pos])) {
        return lex_digit(src, len, crs);
    }

    if (isalpha(src[crs->pos])) {
        return lex_alpha(src, len, crs);
    }

    return lex_single(src, len, crs);
}

token_t *lex_file(char *src, size_t len) {
    token_t *head = NULL;
    token_t *tail = NULL;

    cursor_t crs = { 0, 0, 0 };

    while (crs.pos < len) {
        while (crs.pos < len && isspace(src[crs.pos])) {
            cursor_advance(src, &crs);
        }
        if (crs.pos == len) break;
        token_t *token = lex_token(src, len, &crs);
        if (!token) {
            syntax_error(src, &crs);
        }
        if (!head) {
            head = token;
        }
        else {
            tail->next = token;
        }
        tail = token;
    }

    if (tail) {
        tail->next = token_init(&crs, TK_EOF);
    }

    return head;
}