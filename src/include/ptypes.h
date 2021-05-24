#ifndef PLAIN_PTYES_H
#define PLAIN_PTYES_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef int(*producer)(int n, ...);     /* n is the number of varargs */

struct _Operation {
    producer opt;          /* a function that represents an operation. There are 4 basic operations:
                            add, sub, mul, p */
};


typedef struct _Operation operation;

struct _Declaration {
    char* identifier;                    /* name of the declaration */
    int literal;                         /* whether the value is a int-literal or a result of an operation */
    operation* op;                       /* if literal = 1, the pointer to the operation. value is the result
                                         of the operation */
    int value;                           /* value of the declaration */
    int line;                            /* the line which the declaration occurs at */
};

typedef struct _Declaration var_decl;

/* create_operation: create a new operation with the given producer */
void create_operation(operation* op, producer opr);

/* destroy_operation: free the resources of the operation */
void destroy_operation(operation* op);

/* create_decl: create a new variable declaration with the given values */
void create_decl(var_decl* decl, char* identifier, int literal, operation* op, int value, int line);

/* create_empty_decl: create an empty declaration */
void create_empty_decl(var_decl* decl);

/* destroy_decl: free the resources of the declaration */
void destroy_decl(var_decl* decl);


#endif // PLAIN_PTYES_H
