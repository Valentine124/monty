#include "monty.h"

/**
 * free_stack - free a stack
 * @stack: The stack to free
 */
void free_stack(stack_t *stack)
{
	if (!stack)
		return;

	if (stack->next != NULL)
		free_stack(stack->next);

	free(stack);
	stack = NULL;
}

/**
 * stack_len - computes the length of tje stack
 * @stack: The stack
 *
 * Return: The stack len
 */
int stack_len(stack_t *stack)
{
	int len = 0;
	stack_t *temp;

	if (stack == NULL)
		return (0);

	temp = stack;
	while (temp)
	{
		len += 1;
		temp = temp->next;
	}

	return (len);
}
