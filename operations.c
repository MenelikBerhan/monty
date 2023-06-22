#include "monty.h"
#include <ctype.h>

/**
 * is_num - checks if all characters in string str are digits
 * @str: string to be checked
 *
 * Return: 1 if all characters are digits or 0 otherwise.
*/
int is_num(char *str)
{
	int len, i;

	if (!str)
		return (0);
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if (i == len - 1 && str[i] == '\n')
			continue;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * push - pushes an integer to the top of stack
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void push(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	stack_t *new_node;

	if (!ins->opcode || !is_num(ins->opcode))
	{
		fflush(NULL);
		fprintf(stderr, "L%u: usage: push integer\n", l_num);
		fclose(input);
		free_stack(*stack);
		free(ins);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fflush(NULL);
		fprintf(stderr, "Error: malloc failed\n");
		fclose(input);
		free_stack(*stack);
		free(ins);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(ins->opcode);
	new_node->prev = NULL;
	new_node->next = *stack;
	*stack = new_node;
}

/**
 * pop - removes an integer from the top of the stack
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void pop(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	stack_t *temp;

	if (stack_len(*stack) == 0)
	{
		fflush(NULL);
		fprintf(stderr, "L%u: can't pop an empty stack\n", l_num);
		fclose(input);
		free_stack(*stack);
		free(ins);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	if (temp)
		free(temp);
}

/**
 * pall - prints all integers in the stack
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void pall(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	stack_t *s = *stack;
	(void)l_num;
	(void)input;
	(void)ins;

	while (s)
	{
		fprintf(stdout, "%d\n", s->n);
		s = s->next;
	}
}

/**
 * pint - prints the top most integer from the stack
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void pint(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	if (stack_len(*stack) == 0)
	{
		fflush(NULL);
		fprintf(stderr, "L%u: can't pint, stack empty\n", l_num);
		fclose(input);
		free_stack(*stack);
		free(ins);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}
