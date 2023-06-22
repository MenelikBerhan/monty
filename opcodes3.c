#include "monty.h"

/**
 * mod - modulo divides the second top integer with the top integer
 *	from the stack and adds the result on top of the stack after removing
 *	the two integers
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void mod(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	int result;
	stack_t *temp;

	if (stack_len(*stack) < 2)
	{
		fflush(NULL);
		fprintf(stderr, "L%u: can't mod, stack too short\n", l_num);
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
	result = ((*stack)->next)->n % (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	(*stack)->n = result;
	free(temp);
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void pchar(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	if (!stack_len(*stack))
	{
		fflush(NULL);
		fprintf(stderr, "L%u: can't pchar, stack empty\n", l_num);
		fclose(input);
		free_stack(*stack);
		free(ins);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fflush(NULL);
		fprintf(stderr, "L%u: can't pchar, value out of range\n", l_num);
		fclose(input);
		free_stack(*stack);
		free(ins);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void pstr(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	stack_t *temp;

	(void)l_num;
	(void)input;
	(void)ins;

	temp = *stack;
	while (temp && !(temp->n < 1 || temp->n > 127))
	{
		fprintf(stdout, "%c", temp->n);
		temp = temp->next;
	}
	fprintf(stdout, "\n");
}

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void rotl(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	(void)input;
	(void)stack;
	(void)l_num;
	(void)ins;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void rotr(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	(void)input;
	(void)stack;
	(void)l_num;
	(void)ins;
}
