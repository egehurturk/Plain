#include "include/token.h"

void token_create(token* tok, int type, int data, int line, var_decl decl) {
    tok->type = type;
    tok->data = data;
    tok->line = line;
    tok->decl = decl;
}

void token_destroy(token* tok) {
    // free(tok);
}

void token_list_create(token_list* list, int size) {
    list->data = (token*) malloc(sizeof(token) * size);
    list->ptr = 0;
    list->size = size;
}

void token_list_add(token_list* list, token tok) {
    if (list->ptr >= list->size) {
		list->size *= 2;
		list->data = (token*) realloc(list->data, sizeof(token) * list->size);
	}

	token* t = &list->data[list->ptr++];
	token_create(t, tok.type, tok.data, tok.line, tok.decl);
}

token* token_list_get(token_list* list, int index) {
    return &list->data[index];
}

void token_list_destroy(token_list* list) {
    for (int i = 0; i < list->ptr; i++) {
    		token_destroy(&list->data[i]);
    }
    free(list->data);
}
