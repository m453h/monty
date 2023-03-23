#include "monty.h"

/**
* pop - removes the top element of the stack.
* @head: pointer to the pointer of a head to a stack
* @counter: line count
*
* Return: (void)
*/
void pop(stack_t **head, unsigned int counter)
{
	stack_t *iterator;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	iterator = *head;
	*head = iterator->next;
	free(iterator);
}

/**
* swap - swaps the top two elements of the stack.
* @head: head of stack
* @counter: line count
*
* Return: (void)
*/
void swap(stack_t **head, unsigned int counter)
{
	stack_t *iterator;
	int length = 0, tmp_stack;

	iterator = *head;

	while (iterator)
	{
		iterator = iterator->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	iterator = *head;
	tmp_stack = iterator->n;
	iterator->n = iterator->next->n;
	iterator->next->n = tmp_stack;
}
