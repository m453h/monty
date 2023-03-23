#include "monty.h"

/**
* pchar - prints the char at the top of the stack, followed by a new line.
* @head: stack head
* @counter: line count
*
* Return: nothing
*/
void pchar(stack_t **head, unsigned int counter)
{
	stack_t *iterator;

	iterator = *head;

	if (!iterator)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (iterator->n > 127 || iterator->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", iterator->n);
}
