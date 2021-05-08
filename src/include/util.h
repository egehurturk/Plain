#ifndef PLAIN_UTIL_H
#define PLAIN_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_FIL_LEN 1 << 20
#define ERR(outp, msg) fprintf(outp, msg);
#define PRINT_USG() ERR(stderr, "Usage: ./plain <plain_script>\n")
#define min(a, b) ( (a) < (b) ? (a) : (b) )

#define OUTC 0
#define INC  1

/* Read file into string */
char* read_ascii_file(const char* path);

/* Preprocess file */
char* preprocess_source(char* source);

/* ~Private~ remove comments */
static char* preprocess_comments(char* source);

/* ~Private~ separate compound declerations into each line */
static char* preprocess_compound_declaration(char* source);

 /* ~Private~ remove multiple \n in the same sequence */
static char* preprocess_mult_nl(char* source);

/* print string literal */
void print_lit(char* p);

#endif // PLAIN_UTIL_H
