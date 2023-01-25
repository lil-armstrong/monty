#include "monty.h"

/**
 * pall - print all the values on the stack,
 * starting from the top of the stack
 * @stack: top of the stack
 */
void pall(stack_t *stack)
{
	if (stack == NULL)
		return;

	toTop(&stack);

	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->prev;
	}
}
