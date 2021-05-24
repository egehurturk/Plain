#include "include/ptypes.h"


void create_operation(operation* op, producer opr) {
    op->opt = opr;
}

void destroy_operation(operation* op) {
    free(op);
}

void create_decl(var_decl* declaration, char* identifier, int literal, operation* op, int value, int line) {
    declaration->identifier = identifier;
    declaration->literal = literal;
    declaration->op = op;
    declaration->value = value;
    declaration->line = line;
}

void create_empty_decl(var_decl* declaration) {
    declaration->identifier = NULL;
    declaration->literal = 0;
    declaration->op = NULL;
    declaration->value = 0;
    declaration->line = 0;
}

void destroy_decl(var_decl* decl) {
    destroy_operation(decl->op);
    free(decl);
}
