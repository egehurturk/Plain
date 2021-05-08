#include "include/util.h"

// #define DEBUG

#ifndef DEBUG
    #define D if(0)
#else
    #define D if(1)
#endif

char* read_ascii_file(const char* path) {
	// Create a file
	FILE* file = fopen(path, "r");
	if (!file) {
		printf("Could not open file '%s'\n", path);
		return NULL;
	}

	// Get the file size
	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fseek(file, 0, SEEK_SET);

	// Read file
	char* buf = (char*) malloc(sizeof(char) * (size + 1));
	if (!buf) {
		printf("Could not allocate memory for file!\n");
		return NULL;
	}
	fread(buf, 1, size, file);
	buf[size] = '\0';
	fclose(file);

	// Return contents
	return buf;
}


char* preprocess_source(char* source) {
    char* buf = preprocess_comments(source);
    if (buf == NULL) {
        free(buf);
        return NULL;
    }
    char* f_buf = preprocess_mult_nl(buf);
    if (f_buf == NULL) {
        free(f_buf);
        return NULL;
    }
    // return f_buf;
    char* ff_buf = preprocess_compound_declaration(f_buf);
    return ff_buf;
    // if (ff_buf == NULL) {
    //     free(f_buf);
    //     return NULL;
    // }
    // return ff_buf;
}




static char* preprocess_comments(char* source) {
    int fp, bp = 0;

    char* buf = (char*) malloc(sizeof(char) * (strlen(source) + 1)); // don't forget \0

    if (buf == NULL) {
        fprintf(stderr, "%s\n", "Something bad happened to memory");
        return NULL;
    }


    for (fp = 0; source[fp] != '\0'; fp++) {
        char cur = source[fp];
        if (source[fp] != '?')
            buf[bp++] = source[fp];
        else {
            while (source[fp] != '\n') fp++;
            // source[fp] = '\n'
            // step back from '\n'
            fp--;
        }
    }
    return buf;
}

static char* preprocess_compound_declaration(char* source) {
    char* nbuf = (char*) malloc(sizeof(char) * (strlen(source) + 1));

    if (nbuf == NULL) {
        fprintf(stderr, "%s\n", "Something bad happened to memory");
        return NULL;
    }


}


static char* preprocess_mult_nl(char* source) {
    char* jbuf = (char*) malloc(sizeof(char) * (strlen(source) + 1)); // don't forget \0

    if (jbuf == NULL) {
        fprintf(stderr, "%s\n", "Something bad happened to memory");
        return NULL;
    }
    int fb = 0, bp = 0, nn = 0;

    for (; source[fb] != '\0'; fb++) {
        while (source[fb] == '\n') nn++, fb++;
        if (nn >= 1) {
            fb--;
            jbuf[bp++] = source[fb];
        }
        else
            jbuf[bp++] = source[fb];
        nn = 0;
    }
    return jbuf;
}

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
