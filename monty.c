#include "monty.h"

/**
 * main - Entry point for the monty bytecode interpreter
 * @argc: The arguments count
 * @argv: The arguments vector
 *
 * Return: Always Success 0
 *
 * Description: The program will take a monty bytecode
 * file as input and executes the instruction on each
 * line of the file.
 * The execution of each line is an operation on the stack
 * and queue data structure.
 * Example of instructions it executes:
 * 1. push <int>: add an element to the top of the stack
 * 2. pail: prints all the values on the stack, starting
 * from the top of the stack. etc.
*/
int main(int argc, char **argv)
{
	stack_t *head = NULL;
	struct stat buff;
	int fd, rd, i;
	char *line[1024];
	char str[1024], *token = NULL;

	stack = &head;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (stat(argv[1], &buff) == 0)
	{
		fd = open(argv[1], O_RDONLY);
		rd = read(fd, str, 1024);

		if (fd == -1 || rd == -1)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		str[rd] = '\0';
		token = strtok(str, "\n");
		i = 0;
		while (token)
		{
			line[i] = token;
			token = strtok(NULL, "\n");
			i++;
		}
		line[i] = NULL;
		parse_lines(line);
		close(fd);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (0);
}
