#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number, FILE *input);
} instruction_t;
instruction_t *ins;


void push(stack_t **stack, unsigned int line_number, FILE *input);
void pop(stack_t **stack, unsigned int line_number, FILE *input);
void pall(stack_t **stack, unsigned int line_number, FILE *input);
void pint(stack_t **stack, unsigned int line_number, FILE *input);
void swap(stack_t **stack, unsigned int line_number, FILE *input);
void add(stack_t **stack, unsigned int line_number, FILE *input);
void nop(stack_t **stack, unsigned int line_number, FILE *input);
void sub(stack_t **stack, unsigned int line_number, FILE *input);
void _div(stack_t **stack, unsigned int line_number, FILE *input);
void mul(stack_t **stack, unsigned int line_number, FILE *input);
void mod(stack_t **stack, unsigned int line_number, FILE *input);
void pchar(stack_t **stack, unsigned int line_number, FILE *input);
void pstr(stack_t **stack, unsigned int line_number, FILE *input);
void rotl(stack_t **stack, unsigned int line_number, FILE *input);
void rotr(stack_t **stack, unsigned int line_number, FILE *input);
void _stack(stack_t **stack, unsigned int line_number, FILE *input);
void queue(stack_t **stack, unsigned int line_number, FILE *input);

void assign_f(void);
size_t stack_len(const stack_t *h);
void free_stack(stack_t *head);

#endif
