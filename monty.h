#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <sys/types.h>
#include<string.h>
#define _GNU_SOURCE
#include <stdio.h>

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct bus_s - carries important data throughout the program life cylce
* @arg: value
* @file: pointer to file containing monty source code
* @content: monty file line content
* @type: flag specifies data structure type whether stack or queue
*/
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int type;
}  bus_t;
extern bus_t bus;

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void print_stack(stack_t **head, unsigned int counter);
void add_node(stack_t **head, int n);
void print_queue(stack_t **head, unsigned int counter);
void add_to_queue(stack_t **head, int n);
void push(stack_t **head, unsigned int number);
void pall(stack_t **head, unsigned int number);
void pint(stack_t **head, unsigned int counter);
void pop(stack_t **head, unsigned int counter);
void swap(stack_t **head, unsigned int counter);
void add(stack_t **head, unsigned int counter);
void nop(stack_t **head, unsigned int counter);
void sub(stack_t **head, unsigned int counter);
void _div(stack_t **head, unsigned int counter);
void mul(stack_t **head, unsigned int counter);
void mod(stack_t **head, unsigned int counter);
void pchar(stack_t **head, unsigned int counter);
void pstr(stack_t **head, unsigned int counter);
void rotl(stack_t **head,  __attribute__((unused)) unsigned int counter);
void rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void set_stack_mode(stack_t **head, unsigned int counter);
void set_queue_mode(stack_t **head, unsigned int counter);
#endif
