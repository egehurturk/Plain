#include "include/main.h"


// ./plain basic.plain

int main(int argc, char* argv[]) {

    if (argc < 2) {
        ERR(stderr, "error: Too few arguments\n");
        PRINT_USG();
        return 1;
    }
    else if (argc > 2) {
        ERR(stderr, "error: Too many arguments\n");
        PRINT_USG();
        return 1;
    }


    const char* source = read_ascii_file(argv[1]);
    char* mod_source = malloc((strlen(source)) * sizeof(char));
    strncpy(mod_source, source,  min(strlen(source), MAX_FIL_LEN));



    mod_source = preprocess_source(mod_source);

    if (mod_source == NULL) {
        return 1;
    }


    printf("%s\n", mod_source);
    free(mod_source);
    free(source);

    return 0;
}
