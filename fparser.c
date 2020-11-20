#include <stdio.h>
#include "include/fparser.h"
#include "include/main.h"

error file_parser(char *filename)
{
	FILE *file = fopen(filename, "r");

	// do stuff ...

	fclose(file);

	return 0;
}
