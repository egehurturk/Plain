#ifndef PLAIN_UTIL_H
#define PLAIN_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


#define MAX_FIL_LEN    1 << 20          /* maximum file length */
#define OUTC           0
#define INC            1

#define ERR(out, msg) fprintf(out, msg)
#define PRINT_USG() ERR(stderr, "Usage: ./plain <plain_script>\n")
#define min(a, b) ( (a) < (b) ? (a) : (b) )

/* read_ascii_file: read the path representing a file into a buffer.
   Note: the allocated space for the buffer is not free'd. It is your
   job to free the buffer returned by this function.
 */
char* read_ascii_file(const char* path);

/* preprocess_source: do operations on the source, e.g., remove comments to preprocess
                      the source code. */
int preprocess_source(char *source[]);

/* preprocess_comments: remove comments */
int preprocess_comments(char *source[]);

/* preprocess_compound_declaration: separate compound declerations into a new line */
int preprocess_compound_declaration(char *source[]);

 /* preprocess_mult_nl: remove multiple \n in a sequence */
int preprocess_mult_nl(char *source[]);

/* print_lit: print string literal */
void print_lit(char* p);

/* _realloc: a wrapper for stdlib realloc function, which checks the result of realloc for NULL values */
static int _realloc(char* p[], size_t size);

#endif // PLAIN_UTIL_H
