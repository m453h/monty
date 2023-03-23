#include "monty.h"

/**
* _div - divides the top two elements of the stack
* @head: pointer to the pointer of a head to a stack
* @counter: line count
*
* Return: (void)
*/
void _div(stack_t **head, unsigned int counter)
{
	stack_t *iterator;
	int length = 0, temp;

	iterator = *head;
	while (iterator)
	{
		iterator = iterator->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	iterator = *head;

	if (iterator->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = iterator->next->n / iterator->n;
	iterator->next->n = temp;
	*head = iterator->next;
	free(iterator);
}
