#include "monty.h"

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
