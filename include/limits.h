
// main.c
#ifndef MAX_FILENAME_SIZE
#define MAX_FILENAME_SIZE 255
#endif
#ifndef MAX_FILES
#define MAX_FILES 16
#endif

// fparser.c
#ifndef MAX_CHAR_STATEMENT
#define MAX_CHAR_STATEMENT 255 // including newline (written statement therefor consists of 254 readable chars and spaces)
#endif
#ifndef MAX_STATEMENTS
#define MAX_STATEMENTS 0xffffffff // number of addresses (unsigned int)
#endif
#ifndef MAX_ARGUMENTS
#define MAX_ARGUMENTS 8
#endif
#ifndef MAX_CHAR_ARGUMENT
#define MAX_CHAR_ARGUMENT 8 // result of max address (MAX_STATEMENTS)
#endif