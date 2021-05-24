#ifndef PLAIN_TOKEN_H
#define PLAIN_TOKEN_H

#include <stdarg.h>
#include <stdlib.h>
#include "ptypes.h"

enum _TokenType {
    OP,
    INT_LIT,
    IDENTIFIER,
};

enum _TokenOperation {
    ADD,
    SUB,
    MUL,
    P
};

typedef enum _TokenOperation token_operation;

struct _Token {
    int type;       /* the data itself */
    int data;       /* data type */
    int line;       /* line */
    var_decl decl;
};

typedef struct _Token token;


/* token_create: creates a new token from heap memory */
void token_create(token* tok, int data, int type, int line, var_decl decl);

/* token_destroy: free the memory space that the token allocates */
void token_destroy(token* tok);

struct _TokenList {
    token* data;   /* list of tokens */
    int ptr;       /* point to the current member */
    int size;
};

typedef struct _TokenList token_list;

/* token_list_create: creates a new token list */
void token_list_create(token_list* list, int size);

/* token_list_add: add a new token to the token list */
void token_list_add(token_list* list, token tok);

/* token_list_get: get the token at position index */
token* token_list_get(token_list* list, int index);

/* token_destroy: destroy the token list */
void token_list_destroy(token_list* list);



#endif // PLAIN_TOKEN_H
