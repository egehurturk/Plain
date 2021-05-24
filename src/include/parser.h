#ifndef PLAIN_PARSER_H
#define PLAIN_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include "token.h"

#define LEXER_BUFFER_SIZE 1 << 8

void parser_start(token_list* list, char* source);



#endif // PLAIN_PARSER_H
