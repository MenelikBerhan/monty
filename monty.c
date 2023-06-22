#include "monty.h"
#include <stdio.h>

/**
 * init_ins - initializes an instruction_t type
 *
*/
void init_ins(void)
{
	ins = malloc(sizeof(instruction_t));
	if (!ins)
	{
		fflush(NULL);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * main - monty scripting language
 * @argc: number of arguments
 * @argv: array of argument strings
 *
 * Return: 0 if success, 1 for failure
*/
int main(int argc, char *argv[])
{
	FILE *input;
	char line[100];
	unsigned int line_n = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	input = fopen(argv[1], "r");
	if (!input)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	init_ins();
	while (fgets(line, 1023, input))
	{
		line_n++;
		ins->opcode = strtok(line, " \n");
		assign_f();
		if (ins->f == NULL)
		{
			fflush(NULL);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, strtok(line, " "));
			free_stack(stack);
			free(ins);
			exit(EXIT_FAILURE);
		}
		ins->opcode = ins->f == push ? strtok(NULL, " \n") : ins->opcode;
		ins->f(&stack, line_n, input);
	}
	fclose(input);
	free_stack(stack);
	free(ins);
	return (0);
}
