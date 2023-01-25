#include "monty.h"

/**
 * push - Push an element to the stack
 * @top: top fo the stack
 * @value: value to the added to the stack
 * Return: Pushed node
 */
void push(stack_t **top, unsigned int value)
{
	stack_t *node;

	node = (stack_t *)malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeStack((*top));
		exit(EXIT_FAILURE);
	}

	node->next = NULL;
	node->prev = NULL;
	node->n = value;

	if ((*top) == NULL)
	{
		(*top) = node;
	}
	else
	{
		/* Get the top of the stack */
		toTop(top);
		node->prev = (*top);
		(*top) = node;
	}
}
