#include "monty.h"

/**
 * add - add the top two elements of the stack
 * @stack: The stack
 * @line_number: The instaruction line in thefile
 */
void add(stack_t **stack, unsigned int line_number)
{
	int len = stack_len(*stack);

	if (*stack)
	{
		if (len < 2)
		{
			fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		else
		{
			int sum;
			stack_t *next = (*stack)->next;

			sum = (*stack)->n + next->n;
			next->n = sum;
			pop(stack, line_number);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop - Do nothing
 * @stack: The stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	return;
}

/**
 * sub - subtract the first two elementof the stack
 * @stack: the stack
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int len = stack_len(*stack);

	if (*stack)
	{
		if (len < 2)
		{
			fprintf(stderr, "L%d: can't sub, stack too short", line_number);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		else
		{
			int diff;
			stack_t *next = (*stack)->next;

			diff = next->n - (*stack)->n;
			next->n = diff;
			pop(stack, line_number);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
