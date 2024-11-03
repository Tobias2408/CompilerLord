#ifndef LEXER_H_
#define LEXER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    BEGINNING,
    INT,
    KEYWORD,
    SEPARATOR,
    OPERATOR,
    END_OF_TOKENS,
} TokenType;

typedef struct {
    TokenType type;
    char *value;
} Token;

void print_token(Token token);
Token *generate_number(char *current, int *current_index);
Token *generate_keyword(char *current, int *current_index);
Token *generate_separator(char *current, int *current_index, TokenType type);
Token *lexer(FILE *file);

extern size_t tokens_index;  // Declare tokens_index for use in main.c

#endif // LEXER_H_
