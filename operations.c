#include "monty.h"

/**
 * push - Add an element to the top of the stack
 * @stack: the stack
 * @data: the data to push
*/
void push(stack_t **stack, int data)
{
	stack_t *new;

	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new->n = data;
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
}

/**
 * pall - prints all data in a stack
 * @stack: the stack to print
 * @line_number: instruction line_number
 *
 * Description: This function print the value of
 * all the data in a stack but prints nothing if
 * the stack is empty.
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (*stack == NULL)
	{
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: The stack
 * @line_number: instruction line_number
 *
 * Description: This function prints the value of
 * the data at the top of a stack but prints nothing if
 * the stack is empty and exits with a failure.
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - Removes the element at the top of a stack
 * @stack: The stack
 * @line_number: instruction line_number
 *
 * Return: The value deleted or NULL if empty
 *
 * Description: This function deletes the value of
 * the data at the top of a stack but deletes nothing if
 * the stack is empty and exit with a failure.
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	free(temp);
}

/**
 * swap - swaps the first two element in the stack
 * @stack: the stack
 * @line_number: file lie number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp, len = 0;
	stack_t *tem;

	if (*stack)
	{
		tem = *stack;
		while (tem)
		{
			len += 1;
			tem = tem->next;
		}

		if (len < 2)
		{
			fprintf(stderr, "L%d: can't swap, stack too short", line_number);
			exit(EXIT_FAILURE);
		}
		else
		{
			stack_t *next = (*stack)->next;

			temp = (*stack)->n;
			(*stack)->n = next->n;
			next->n = temp;

			return;
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
}
