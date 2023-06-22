#include "monty.h"

/**
 * swap - swaps the top and bottom integers from the stack
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
 * add - adds the two top integers from the stack and adds the result
 *	on top of the stack after removing the two integers
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void add(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	int sum;
	stack_t *temp;

	if (stack_len(*stack) < 2)
	{
		fflush(NULL);
		fprintf(stderr, "L%u: can't add, stack too short\n", l_num);
		fclose(input);
		free_stack(*stack);
		free(ins);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + ((*stack)->next)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	(*stack)->n = sum;
	free(temp);
}

/**
 * sub - subtracts the second top integer from the top integer in the stack
 *	and adds the result on top of the stack after removing the two integers
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void sub(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	int diff;
	stack_t *temp;

	if (stack_len(*stack) < 2)
	{
		fflush(NULL);
		fprintf(stderr, "L%u: can't sub, stack too short\n", l_num);
		fclose(input);
		free_stack(*stack);
		free(ins);
		exit(EXIT_FAILURE);
	}
	diff = ((*stack)->next)->n - (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	(*stack)->n = diff;
	free(temp);
}

/**
 * _div - divdes the second top integer with the top integer from the stack
 *	and adds the result on top of the stack after removing the two integers
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void _div(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	int result;
	stack_t *temp;

	if (stack_len(*stack) < 2)
	{
		fflush(NULL);
		fprintf(stderr, "L%u: can't div, stack too short\n", l_num);
		fclose(input);
		free_stack(*stack);
		free(ins);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fflush(NULL);
		fprintf(stderr, "L%u: division by zero\n", l_num);
		fclose(input);
		free_stack(*stack);
		free(ins);
		exit(EXIT_FAILURE);
	}
	result = ((*stack)->next)->n / (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	(*stack)->n = result;
	free(temp);
}

/**
 * mul - multiplies the two top integers from the stack with each other and
 *	adds the result on top of the stack after removing the two integers
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void mul(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	int result;
	stack_t *temp;

	if (stack_len(*stack) < 2)
	{
		fflush(NULL);
		fprintf(stderr, "L%u: can't mul, stack too short\n", l_num);
		fclose(input);
		free_stack(*stack);
		free(ins);
		exit(EXIT_FAILURE);
	}
	result = ((*stack)->next)->n * (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	(*stack)->n = result;
	free(temp);
}
