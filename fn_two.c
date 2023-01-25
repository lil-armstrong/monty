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
