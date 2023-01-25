#include "monty.h"

/* AUTHOR: lil-armstrong */

/**
 * main - Main program
 * @argc: Argument count
 * @argv: List of program arguments
 * Return: 0 (success) otherwise (fail)
 */
int main(int argc, char **argv)
{
	char *file_name;

	/* Check arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_name = argv[1];
	openFileForParsing(file_name, fileParser);

	exit(EXIT_SUCCESS);
}
