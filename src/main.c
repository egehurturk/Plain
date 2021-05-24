#include "include/main.h"


// ./plain basic.plain

int main(int argc, char* argv[]) {

    // Argument checking

    if (argc < 2) {
        ERR(stderr, "plain (error): Too few arguments\n");
        PRINT_USG();
        return 1;
    }
    else if (argc > 2) {
        ERR(stderr, "plain (error): Too many arguments\n");
        PRINT_USG();
        return 1;
    }


    // Read the source file into a buffer, do operations on it
    char* source = read_ascii_file(argv[1]);

    if (source == NULL) {
        return 1;
    }

    char* mod_source = calloc(strlen(source), sizeof(char));
    strncpy(mod_source, source, strlen(source));

    if (!preprocess_source(&mod_source)) {
        return 1;
    }


    printf("%s\n", mod_source);
    // Clean up the resources
    free(mod_source);
    free(source);

    return 0;
}
