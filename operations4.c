#include "monty.h"

/**
 * _stack - sets the format of the data to a queue (FIFO)
 * @stack: pointer to a stack_t list
 * @line_number: line number of push command in file argument
 * @input: stream created from file argument
 *
*/
void _stack(stack_t **stack, unsigned int line_number, FILE *input)
{
	(void)input;
	(void)stack;
	(void)line_number;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to a stack_t list
 * @line_number: line number of push command in file argument
 * @input: stream created from file argument
 *
*/
void queue(stack_t **stack, unsigned int line_number, FILE *input)
{
	(void)input;
	(void)stack;
	(void)line_number;
}

/**
 * nop - does nothing
 * @stack: pointer to a stack_t list
 * @line_number: line number of push command in file argument
 * @input: stream created from file argument
 *
*/
void nop(stack_t **stack, unsigned int line_number, FILE *input)
{
	(void)input;
	(void)stack;
	(void)line_number;
}
