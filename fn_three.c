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
 * swap - swap two elements from the stack.
 * One from the top of the stack
 * the other from the bottom of the stack
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
 */
void nop(void)
{}
