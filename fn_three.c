#include "monty.h"

/* AUTHOR: lil-armstrong */

/**
 * pint - Print value at the top of stack
 * @top: top of stack
 * @line_number: current line number
 */
void pint(stack_t **top, unsigned int line_number)
{
	if ((*top) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}

	toTop(top);

	printf("%d\n", (*top)->n);
}

/**
 * swap - swap the top two elements on the stack.
 * @top: top of stack
 * @line_number: current line number of command
 */
void swap(stack_t **top, unsigned int line_number)
{
	int temp;

	if (!hasElement((*top), 2))
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	toTop(top);

	temp = (*top)->n;
	(*top)->n = (*top)->prev->n;
	(*top)->prev->n = temp;
}
/**
 * add - add the top two elements from the stack.
 * @top: top of stack
 * @line_number: current line number of command
 */
void add(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	if (!hasElement((*top), 2))
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	toTop(top);

	temp = (*top);
	(*top) = temp->prev;
	(*top)->n = temp->n + (*top)->n;
	free(temp);
	(*top)->next = NULL;
}

/**
 * pop - pop from the stack
 * @top: top element of the stack
 * @line_number: line number of command
 */
void pop(stack_t **top, unsigned int line_number)
{
	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an emptystack", line_number);
		exit(EXIT_FAILURE);
	}

	toTop(top);

	if ((*top)->prev)
	{
		/* Remove the top element of the stack */
		(*top) = (*top)->prev;
		free((*top)->next);
		(*top)->next = NULL;
	}
	else
	{
		free((*top));
		(*top) = NULL;
	}
}

/**
 * nop - does nothing
 * @stack: top of stack
 * @line_number: current line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}
