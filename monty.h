#ifndef MONTY_H
#define MONTY_H
/* AUTHOR: lil-armstrong */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TEST 0

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* fn_one */
void fileParser(FILE *);
void openFileForParsing(const char *filename, void (*parser)(FILE *));
int hasElement(stack_t *stack, unsigned int num);
void toTop(stack_t **stack);
void lineParser(char *line, unsigned int, stack_t **stack);

/* fn_two */
void freeStack(stack_t *stack);
void pall(stack_t *);
void push(stack_t **stack, unsigned int value);

/* fn_three */
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void nop(void);

#endif /* End of MONTY header guard */
