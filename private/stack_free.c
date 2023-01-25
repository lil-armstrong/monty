#include "monty.h"

/* AUTHOR: lil-armstrong */

/**
 * freeStack - Free the stack
 * @top: the top of the stack
 */
void freeStack(stack_t *top)
{
	stack_t *temp;

	if (top == NULL)
		return;

	toTop(&top);
	while (top->prev != NULL)
	{
		temp = top;
		top = top->prev;
		free(temp);
		top->next = NULL;
	}

	free(top);
	top = NULL;
}
