#ifndef PLAIN_TOKEN_H
#define PLAIN_TOKEN_H

struct _Token {
    int data;       /* the data itself */
    int type;       /* data type */
    int line;       /* line */
};

typedef struct _Token token;

/* token_create: creates a new token from heap memory */
token* token_create(int data, int type, int line);

/* token_destroy: free the memory space that the token allocates */
void token_destroy(token* tok);

struct _TokenList {
    token** data;  /* list of token pointers */
    int ptr;       /* point to the current member */
    int size;
};

typedef struct _TokenList token_list;

/* token_list_create: creates a new token list */
token_list* token_list_create(int size);

/* token_list_add: add a new token to the token list */
void token_list_add(token_list* list, token* tok);

/* token_list_get: get the token at position index */
token* token_list_get(token_list* list, int index);

/* token_destroy: destroy the token list */
void token_list_destroy(token_list* list);



#endif // PLAIN_TOKEN_H
