#include "monty.h"

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
