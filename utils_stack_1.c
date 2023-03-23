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
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
