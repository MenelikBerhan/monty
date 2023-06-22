#include "monty.h"

/**
 * assign_f - assigns a function to handle the op code in ins
 * @ins: pointer to an ins_t type
 *
*/
void assign_f(ins_t *ins)
{
	char *op;

	op = ins->opcode;
	if (!op || op[0] == '#' || (!strncmp(op, "nop", 3) && strlen(op) == 3))
		ins->f = nop;
	else if (!strncmp(op, "push", 4) && strlen(op) == 4)
		ins->f = push;
	else if (!strncmp(op, "pop", 3) && strlen(op) == 3)
		ins->f = pop;
	else if (!strncmp(op, "pall", 4) && strlen(op) == 4)
		ins->f = pall;
	else if (!strncmp(op, "pint", 4) && strlen(op) == 4)
		ins->f = pint;
	else if (!strncmp(op, "swap", 4) && strlen(op) == 4)
		ins->f = swap;
	else if (!strncmp(op, "add", 3) && strlen(op) == 3)
		ins->f = add;
	else if (!strncmp(op, "sub", 3) && strlen(op) == 3)
		ins->f = sub;
	else if (!strncmp(op, "div", 3) && strlen(op) == 3)
		ins->f = _div;
	else if (!strncmp(op, "mul", 3) && strlen(op) == 3)
		ins->f = mul;
	else if (!strncmp(op, "mod", 3) && strlen(op) == 3)
		ins->f = mod;
	else if (!strncmp(op, "pchar", 4) && strlen(op) == 4)
		ins->f = pchar;
	else if (!strncmp(op, "pstr", 4) && strlen(op) == 4)
		ins->f = pstr;
	else if (!strncmp(op, "rotl", 4) && strlen(op) == 4)
		ins->f = rotl;
	else if (!strncmp(op, "rotr", 4) && strlen(op) == 4)
		ins->f = rotr;
	else if (!strncmp(op, "stack", 5) && strlen(op) == 5)
		ins->f = _stack;
	else if (!strncmp(op, "queue", 5) && strlen(op) == 5)
		ins->f = queue;
	else
		ins->f = NULL;
}

/**
 * stack_len - finds number of nodes in a stack_t list
 * @h: a doubly linked stack_t list
 *
 * Return: number of nodes in h
*/
size_t stack_len(const stack_t *h)
{
	size_t len = 0;

	while (h)
	{
		len++;
		h = h->next;
	}

	return (len);
}

/**
 * print_stack - prints all nodes of a doubly linked stack_t list
 * @h: a doubly linked stack_t list
 *
 * Return: number of nodes in h
*/
size_t print_stack(const stack_t *h)
{
	size_t len = 0;

	while (h)
	{
		printf("%d\n", h->n);
		len++;
		h = h->next;
	}

	return (len);
}

/**
 * free_stack - frees a stack_t list
 * @head: a doubly linked stack_t list
 *
*/
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
