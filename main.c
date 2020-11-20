#include <stdio.h>
#include <string.h>
#include "include/main.h"

/////////////////////////////////////////////////////////
//  GLOBAL DEFINITIONS ONLY FOR THIS TRANSLATION UNIT  //
/////////////////////////////////////////////////////////

#ifndef MAX_FILENAME_SIZE
#define MAX_FILENAME_SIZE 255
#endif
#ifndef MAX_FILES
#define MAX_FILES 16
#endif

// changable globals
static char files[MAX_FILES][MAX_FILENAME_SIZE]; // script files
static unsigned char file_counter = 0;			 // number of files given
static char flags[] = {
	// each argument has its own flag in order for other functions to know which argument was given
	0, // help
	0, // verbose
	0  // version
};

///////////////////////////////////////
//  FUNCTIONS FOR CERTAIN ARGUMENTS  //
///////////////////////////////////////

void print_help()
{
	puts("Usage: ");
	puts("Options:");
	puts("      --help        Display helping information");
	puts("  -v, --verbose     Enable verbose output");
	puts("      --version     Display the version of the program");
}

void print_version()
{
	puts("sequential (<platform>) <version>");
	puts("by Steven-Leander Fuchs");
	puts("<license>");
}

///////////////////////////////////////////////////
//  FUNCTIONS FOR ARGUMENT HANDLING AND PARSING  //
///////////////////////////////////////////////////

void argument(char *arg)
{
	size_t arg_length = strlen(arg);
	size_t iter_arg = 0;

	if (arg[0] == '-' && arg[1] == '-') // long arguments
	{
		if (strcmp("--help", arg) == 0 && !flags[HELP_FLAG_INDEX])
		{
			print_help();
			flags[HELP_FLAG_INDEX] = 1;
		}
		if (strcmp("--verbose", arg) == 0 && !flags[VERBOSE_FLAG_INDEX])
		{
			flags[VERBOSE_FLAG_INDEX] = 1;
		}
		if (strcmp("--version", arg) == 0 && !flags[VERSION_FLAG_INDEX])
		{
			print_version();
			flags[VERSION_FLAG_INDEX] = 1;
		}
	}
	else if (arg[0] == '-' && arg[1] != '-') // short arguments
	{
		for (iter_arg = 1; iter_arg < arg_length; iter_arg++) // skip first dash
		{
			if (arg[iter_arg] == 'v' && !flags[VERBOSE_FLAG_INDEX])
			{
				flags[VERBOSE_FLAG_INDEX] = 1;
			}
			else
			{
				printf("Argument \"%c\" is unknown!\n", arg[iter_arg]);
			}
		}
	}
	else // assuming it's a file
	{
		if (file_counter != MAX_FILES)
		{
			if (arg_length <= MAX_FILENAME_SIZE)
			{
				strcpy(files[file_counter], arg);
				file_counter++;
			}
			else
			{
				printf("The size of the filename exceeded the limit of %u characters!\n", MAX_FILENAME_SIZE);
			}
		}
		else
		{
			printf("The number of files exceeded the limit of %u files!\n", MAX_FILES);
		}
	}
}

/////////////////////
//  MAIN FUNCTION  //
/////////////////////

int main(int argc, char **argv)
{
	int iter = 0;

	if (argc == 1)
	{
		puts("No arguments were given.");
		puts("Please use \"--help\" for more information.");
		return 0;
	}
	else
	{
		for (iter = 1; iter < argc; iter++) // skip first arg
		{
			argument(argv[iter]);

			if (flags[HELP_FLAG_INDEX] || flags[VERSION_FLAG_INDEX]) // quit due to terminating args
				return 0;
		}
	}

	if (file_counter == 0)
	{
		puts("No file was given!");
		return -1;
	}

	if (flags[VERBOSE_FLAG_INDEX]) // verbose
	{
		puts("Verbose output was activated.");
		puts("Given files:");

		for (iter = 0; iter < file_counter; iter++)
		{
			printf(" %i. %s", iter + 1, files[iter]);
		}
	}

	// do stuff for parsing and runtime ...

	return 0;
}