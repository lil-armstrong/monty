#include "monty.h"

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
