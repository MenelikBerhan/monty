#include "monty.h"

/**
 * swap - swaps the most top and bottom integers from the stack
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void swap(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	int temp;

	if (stack_len(*stack) < 2)
	{
		fflush(NULL);
		fprintf(stderr, "L%u: can't swap, stack too short\n", l_num);
		fclose(input);
		free_stack(*stack);
		free(ins);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = temp;
}

/**
 * add - adds the two most top integers from the stack and adds
 *	the result on top of the stack after removing the two integers
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void add(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	if (stack_len(*stack) < 2)
	{
		fflush(NULL);
		fprintf(stderr, "L%u: can't add, stack too short\n", l_num);
		fclose(input);
		free_stack(*stack);
		free(ins);
		exit(EXIT_FAILURE);
	}

}

/**
 * sub - subtracts the second most top integer from the most top integer
 *	in the stack and adds the result on top of the stack after removing
 *	the two integers
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void sub(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	(void)input;
	(void)stack;
	(void)l_num;
	(void)ins;
}

/**
 * _div - divdes the most top integer with the second most top integer from
 *	the stack and adds the result on top of the stack after removing
 *	the two integers
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void _div(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	(void)input;
	(void)stack;
	(void)l_num;
	(void)ins;
}

/**
 * mul - multiplies the two most top integers from the stack with each other
 *	and adds the result on top of the stack after removing the two integers
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void mul(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	(void)input;
	(void)stack;
	(void)l_num;
	(void)ins;
}
