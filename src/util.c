#include "include/util.h"

// #define DEBUG

#ifndef DEBUG
    #define D if(0)
#else
    #define D if(1)
#endif



/*      ~ FILE I/0 ~        */

char* read_ascii_file(const char* path) {
	// Create a file
	FILE* file = fopen(path, "r");
	if (!file) {
        fprintf(stderr, "plain (error): Could not open file '%s' \n", path);
		return NULL;
	}

	// Get the file size
	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fseek(file, 0, SEEK_SET);

	// Read file
	char* buf = (char*) malloc(sizeof(char) * (size + 1));
	if (!buf) {
        ERR(stderr, "plain (error): Could not allocate memory for file!\n");
		return NULL;
	}
	fread(buf, 1, size, file);
	buf[size] = '\0';
	fclose(file);
	// Return contents
	return buf;
}

/*      ~ PREPROCESSING ~        */

int preprocess_source(char *source[]) {
    if (!preprocess_comments(source))
        return 0;
    if (!preprocess_mult_nl(source))
        return 0;
    return 1;
}

int preprocess_comments(char *source[]) {
    int fp, bp = 0;

    char* buf = (char *) calloc(sizeof(*source), sizeof(char));

    if (buf == NULL) {
        fprintf(stderr, "%s\n", "Something bad happened to memory");
        return 0;
    }


    for (fp = 0; (*source)[fp] != '\0'; fp++) {
        char cur = (*source)[fp];
        if ( cur != '?') {
            buf[bp++] = cur;
        }
        else {
            while ( (*source)[fp] != '\n')
                fp++;

            // step back from '\n'
            fp--;
        }
    }

    // resize the source
    if (!_realloc(source, strlen(buf)))
        return 0;

    // assign the source to this buffer
    strcpy(*source, buf);

    free(buf);

    return 1;
}



int preprocess_mult_nl(char *source[]) {
    int fb, bp = 0, nn = 0;

    char* jbuf = (char*) calloc(strlen(*source), sizeof(char));

    if (jbuf == NULL) {
        fprintf(stderr, "%s\n", "Something bad happened to memory");
        return 0;
    }

    for (fb = 0; (*source)[fb] != '\0'; fb++) {
        while ((*source)[fb] == '\n') nn++, fb++;
        if (nn >= 1) {
            fb--;
            jbuf[bp++] = (*source)[fb];
        }
        else
            jbuf[bp++] = (*source)[fb];
        nn = 0;
    }
    // resize the source
    if (!_realloc(source, strlen(jbuf)))
        return 0;


    // assign the source to this buffer
    strcpy(*source, jbuf);

    free(jbuf);

    return 1;
}

/*      ~ UTIL ~        */

void print_lit(char* p) {
    int i;
    for (i = 0; p[i] != '\0'; i++)
        if (p[i] == '\n')
            printf("\\n");
        else if (p[i] == ' ')
            putchar(' ');
        else if (p[i] == '\t')
            printf("\\t");
        else
            putchar(p[i]);
}


static int _realloc(char* p[], size_t size) {
    char* temp = realloc(*p, size);
    if (temp != NULL) {
        *p = temp;
        return 1;
    }
    return 0;
}
