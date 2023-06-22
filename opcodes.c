#include "monty.h"

/**
 * push_helper - checks if proper argument is provided for push
 * @stack: pointer to a stack_t list
 * @l_num: line number of push command in file argument
 * @input: stream created from file argument
 * @ins: pointer to an ins_t type
 *
*/
void push_helper(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins)
{
	if (!ins->opcode || !is_num(ins->opcode))
	{
		fflush(NULL);
		fprintf(stderr, "L%u: usage: push integer\n", l_num);
		fclose(input);
		free_stack(*stack);
		free(ins);
		exit(EXIT_FAILURE);
	}
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
	stack_t *new_node, *last_node;
	int len;

	push_helper(stack, l_num, input, ins);
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
	if (mode == 0)
	{
		new_node->n = atoi(ins->opcode);
		new_node->prev = NULL;
		new_node->next = *stack;
		*stack = new_node;
	}
	else
	{
		new_node->n = atoi(ins->opcode);
		new_node->next = NULL;
		len = stack_len(*stack);
		last_node = *stack;
		while (len > 1)
		{
			last_node = last_node->next;
			len--;
		}
		if (!last_node)
			*stack = new_node;
		else
			last_node->next = new_node;
		new_node->prev = last_node ? last_node : NULL;
	}
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
