#include "monty.h"

/**
* set_stack_mode - sets the format of the data to a stack (LIFO)
* @head: pointer to the pointer of a head to a stack_t
* @counter: line count
*
* Return: (void)
*/
void set_stack_mode(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.type = 0;
}

/**
* set_queue_mode - sets the format of the data to a queue (FIFO)
* @head: pointer to the pointer of a head to a stack_t
* @counter: line count
*
* Return: (void)
*/
void set_queue_mode(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.type = 1;
}