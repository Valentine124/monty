#include "monty.h"

/**
 * parse_lines - parse each instruction in the file
 * @line: A list of all instructions in file
 */
void parse_lines(char *line[])
{
	unsigned int line_number = 0, i = 0;

	while (line[i])
	{
		line_number++;
		handle_opcode(line[i], line_number);
		i++;
	}
}
