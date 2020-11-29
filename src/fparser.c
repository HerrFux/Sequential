#include <stdio.h>
#include <string.h>
#include "fparser.h"
#include "limits.h"
#include "main.h"

char validator(char *statement)
{
	// todo: call divider for statement register
	// todo: add to statement register if successful
	memset(statement, 0, MAX_CHAR_ARGUMENT); // empty string
	return 0;
}

char file_parser(char *filename)
{
	FILE *file = fopen(filename, "r");
	char statement[MAX_CHAR_STATEMENT];
	short byte = 0; // needs to be able to read 0xff bytes without confusion with EOF (-1 and 255 are both completely positive)
	unsigned char iter_statement = 0;
	unsigned int iter_address = 0;
	char end_of_file = 0;

	if (!file)
	{
		printf("\"%s\" could not be opened!\n", filename);
		return -1;
	}

	memset(statement, 0, MAX_CHAR_ARGUMENT); // empty string

	while (!end_of_file)
	{
		byte = fgetc(file);

		if (byte == '\n' || byte == EOF) // if end of statement or file
		{
			if (!statement[0]) // if first byte is null (string is empty)
			{
				printf("Empty statement at %i!\n", iter_address);
				return -1;
			}

			if (VERBOSE_ACTIVE) // print verbose output before validation
			{
				printf("Validating \"%s\" at %i ...\n", statement, iter_address);
			}

			if (validator(statement)) // validate statement
			{
				printf("Illegal statement at %i!\n", iter_address);
				printf("'-> \"%s\"\n", statement);
				return -2;
			}

			iter_address++;
			iter_statement = 0;

			if (byte == EOF) // if end of file stop loop
			{
				end_of_file = 1;
			}

			continue;
		}

		if (iter_statement == MAX_CHAR_STATEMENT - 1) // if byte 255 is still not a newline, starting from 1 (0 -> 255 chars is 256 in total and should only be 255)
		{
			printf("Statement exceeded character limit at %i!\n", iter_address);
			printf("'-> \"%s\"\n", statement);
			return -3;
		}

		if (iter_address == MAX_STATEMENTS)
		{
			puts("Too many statements!");
			return -4;
		}

		statement[iter_statement] = byte;
		iter_statement++;
	}

	statement_counter = iter_address + 1; // add one because it started from 0

	fclose(file);

	return 0;
}