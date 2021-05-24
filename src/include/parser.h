#ifndef PLAIN_PARSER_H
#define PLAIN_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

#define LEXER_BUFFER_SIZE 1 << 8

enum _ParserStatus {
        P_SUCCESS,
        P_SYNTAX_ERROR
};

typedef enum _ParserStatus parser_status;

parser_status parser_start(token_list* list, char* source);



#endif // PLAIN_PARSER_H
