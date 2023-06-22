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
		void (*f)(stack_t **stack, unsigned int l_num, FILE *input,
					struct instruction_s *ins);
} ins_t;



void push(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins);
void pop(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins);
void pall(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins);
void pint(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins);
void swap(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins);
void add(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins);
void nop(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins);
void sub(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins);
void _div(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins);
void mul(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins);
void mod(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins);
void pchar(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins);
void pstr(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins);
void rotl(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins);
void rotr(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins);
void _stack(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins);
void queue(stack_t **stack, unsigned int l_num, FILE *input, ins_t *ins);

void assign_f(ins_t *ins);
size_t stack_len(const stack_t *h);
void free_stack(stack_t *head);

#endif
