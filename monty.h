#ifndef MONTY_H
#define MONTY_H

/* Header files */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "structures.h"

/* End of heade files */

/* Functions prototypes */

void push(stack_t **stack, int data);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void handle_opcode(char *line, unsigned int line_number);
void handle_push(char *arg, unsigned int line_number);
void parse_lines(char *line[]);
void swap(stack_t **stack, unsigned int line_number);

/* End of function prototypes */

#endif
