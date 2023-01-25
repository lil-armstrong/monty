#define _GNU_SOURCE
#include "monty.h"

/* AUTHOR: lil-armstrong */

/**
 * openFileForParsing - Open the file for parsing
 * @filename: File name to open and parse
 * @parser: Parser for the file
 */
void openFileForParsing(const char *filename, void (*parser)(FILE *))
{
	FILE *fd;

	if (filename != NULL)
	{
		fd = fopen(filename, "r");
		if (fd == NULL)
		{
			fprintf(stderr, "Error: can't open %s\n", filename);
			exit(EXIT_FAILURE);
		}

		/* invoke fn */
		parser(fd);
		fclose(fd);
	}
}

/**
 * hasElement - Check if stack has an element count
 * @top: top of stack
 * @num: element count to check for
 * Return: 1 (success), 0 (fail)
 */
int hasElement(stack_t *top, unsigned int num)
{
	if (top != NULL)
	{
		toTop(&top);

		while (top)
		{
			--num;
			top = top->prev;
			if (num == 0)
				return (1);
		}
	}

	return (0);
}

/**
 * toTop - sets pointer to top of stack
 * @top: pointer to set
 */
void toTop(stack_t **top)
{
	while ((*top)->next != NULL)
		(*top) = (*top)->next;
}

/**
 * fileParser - Parse file using file descriptor
 * @fd: file descriptor
 */
void fileParser(FILE *fd)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack;

	stack = NULL;

	while ((read = getline(&line, &len, fd)) != -1)
	{
		++line_number;
		lineParser(line, line_number, &stack);
	}

	freeStack(stack);
	if (line)
		free(line);
}

/**
 * lineParser - Parse a line from the monty file
 * @line: line to parse
 * @line_number: current line number
 * @stack: stack to process
 */
void lineParser(char *line, unsigned int line_number, stack_t **stack)
{
	char *opcode, *token;
	unsigned int value;

	opcode = strtok(line, " \n\t");
	token = strtok(NULL, " \n\t");

	if (opcode == NULL || opcode[0] == '#')
		return;
	if (strcmp(opcode, "pall") == 0)
		pall(*stack);
	else if (strcmp(opcode, "push") == 0)
	{
		value = (unsigned int)atoi(token);
		if (!(value))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			freeStack(*stack);
			exit(EXIT_FAILURE);
		}
		push(stack, value);
	}
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s", line_number, opcode);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
}
