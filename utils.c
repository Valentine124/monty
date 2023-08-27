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
