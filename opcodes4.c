#include "monty.h"

/**
 * _stack - sets the format of the data to a queue (FIFO)
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void _stack(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	(void)input;
	(void)stack;
	(void)l_num;
	(void)ins;
	mode = 0;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void queue(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	(void)input;
	(void)stack;
	(void)l_num;
	(void)ins;
	mode = 1;
}

/**
 * nop - does nothing
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void nop(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	(void)input;
	(void)stack;
	(void)l_num;
	(void)ins;
}
