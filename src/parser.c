#include "include/parser.h"

parser_status parser_start(token_list* list, char *source) {
    char lex[LEXER_BUFFER_SIZE];
    int lexi = 0;
    int i = 0;
    int line = 1;       /* not working */

    for (;;) {

        while (source[i] != ' ' && source[i] != '\n' && source[i] != '\0' && source[i] != '\t') {
            lex[lexi++] = source[i++];
        }
        lex[lexi] = '\0';

        if (lexi == 0 && (source[i] == '\n' || source[i] == '\t'))  {
            i++;
            if (source[i] == '\n') line++;
            continue;
        }

        /*
        Approach: Split the source file with a delimiter of ".", then process each splitted statement according to
        grammar (see grammar.txt). 
        */

        // def
        // a
        // :=
        // 3.
        // def
        // b
        // :=
        // 9.
        // def
        // s
        // :=
        // add(a,b).
        // p(s).


        // New line
		if (source[i] == '\n') {
			line++;
		}

		// EOF
		else if (source[i] == '\0') {
			break;
		}

		lexi = 0;
		i++;
    }
    return P_SUCCESS;

}
