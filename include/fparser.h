#include "limits.h"

struct parsed_statement
{
	char command[4];
	char arguments[MAX_ARGUMENTS][MAX_CHAR_ARGUMENT];
};
struct parsed_statement statement_register; // todo: implement statement register
unsigned int statement_counter;

char file_parser(char *filename);