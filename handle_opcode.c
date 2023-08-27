#include "monty.h"

/**
 * handle_opcode - reads the monty file and handle each opcode
 * @line: The line of instruction to parse
 * @line_number: The line number for each instruction
 *
 * Description: This function takes the string in each line of
 * the monty file, parse it to get the opcode and argument if
 * needed and call appropriate function for the opcode
*/
void handle_opcode(char *line, unsigned int line_number)
{
	char *token = NULL;
	int i;
	instruction_t instructions[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	if (line)
	{
		token = strtok(line, " \t");

		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \t");
			handle_push(token, line_number);
			return;
		}

		for (i = 0; instructions[i].opcode; i++)
		{
			if (strcmp(instructions[i].opcode, token) == 0)
			{
				instructions[i].f(stack, line_number);
				return;
			}
		}
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_push - handle the push instruction
 * @arg: String to get the argument from
 * @line_number: instruction line number
*/
void handle_push(char *arg, unsigned int line_number)
{
	int argument;

	if (arg)
	{
		argument = atoi(arg);
		if ((arg[0] != '0') && (argument == 0))
		{
			fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		else
		{
			push(stack, argument);
			return;
		}
	}
	else
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}
