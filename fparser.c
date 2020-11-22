#include <stdio.h>
#include "include/fparser.h"
#include "include/main.h"
#include "include/limits.h"

error validator(char *statement)
{
	return 0;
}

error file_parser(char *filename)
{
	FILE *file = fopen(filename, "r");
	char statement[MAX_CHAR_STATEMENT];
	char byte = 0;
	unsigned char iter_statement = 0;
	unsigned int iter_address = 0; // todo: change data type to match limit

	if (!file)
	{
		printf("\"%s\" could not be opened!\n", filename);
		return -1;
	}

	while ((byte = fgetc(file)) != EOF)
	{
		if (byte == '\n') // if end of statement
		{
			if (validator(statement)) // validate statement
			{
				printf("Illegal characters in statement at %i!\n", iter_address);
				printf("'-> %s\n", statement);
				return -1;
			}

			// todo: add to statement register if successful

			iter_address++;
			iter_statement = 0;
		}

		if (iter_statement == MAX_CHAR_STATEMENT)
		{
			printf("Statement exceeded character limit at %i!\n", iter_address);
			printf("'-> %s\n", statement);
			return -2;
		}

		if (iter_address == MAX_STATEMENTS)
		{
			puts("Too many statements!");
			return -3;
		}

		statement[iter_statement] = byte;
		iter_statement++;
	}

	// todo: set max address/statement count

	fclose(file);

	return 0;
}