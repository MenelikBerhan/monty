#include "monty.h"
#include <stdio.h>

/**
 * init_ins - initializes an ins_t type
 *
 * Return: a pointer to an ins_t type
 *
*/
ins_t *init_ins(void)
{
	ins_t *ins;

	ins = malloc(sizeof(ins_t));
	if (!ins)
	{
		fflush(NULL);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (ins);
}

/**
 * init_stream - initializes stream from file name
 * @file_name: name of the file
 *
 * Return: a file stream
*/
FILE *init_stream(char *file_name)
{
	FILE *stream;

	stream = fopen(file_name, "r");
	if (!stream)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	return (stream);
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
	char line[1024];
	unsigned int line_n = 0;
	stack_t *stack = NULL;
	ins_t *ins;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	input = init_stream(argv[1]);
	ins = init_ins();
	while (fgets(line, 1023, input))
	{
		line_n++;
		ins->opcode = strtok(line, " \n");
		assign_f(ins);
		if (ins->f == NULL)
		{
			fflush(NULL);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, strtok(line, " "));
			free_stack(stack);
			free(ins);
			exit(EXIT_FAILURE);
		}
		ins->opcode = ins->f == push ? strtok(NULL, " \n") : ins->opcode;
		ins->f(&stack, line_n, input, ins);
	}
	fclose(input);
	free_stack(stack);
	free(ins);
	return (0);
}
