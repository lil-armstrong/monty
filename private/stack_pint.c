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
