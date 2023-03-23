#include "monty.h"

/**
* pchar - prints the char at the top of the stack, followed by a new line.
* @head: pointer to the pointer of a head to a stack
* @counter: line count
*
* Return: (void)
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

/**
* pstr - prints the string starting at the top of the stack,
* followed by a new line
* @head: pointer to the pointer of a head to a stack
* @counter: line count
*
* Return: (void)
*/
void pstr(stack_t **head, unsigned int counter)
{
	stack_t *iterator;
	(void)counter;

	iterator = *head;
	while (iterator)
	{
		if (iterator->n > 127 || iterator->n <= 0)
		{
			break;
		}
		printf("%c", iterator->n);
		iterator = iterator->next;
	}
	printf("\n");
}

/**
* rotl- rotates the stack to the top
* @head: pointer to the pointer of a head to a stack
* @counter: line count
*
* Return: (void)
*/
void rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *iterator = *head, *h;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	h = (*head)->next;
	h->prev = NULL;

	while (iterator->next != NULL)
	{
		iterator = iterator->next;
	}

	iterator->next = *head;
	(*head)->next = NULL;
	(*head)->prev = iterator;
	(*head) = h;
}

/**
* rotr - rotates the stack to the bottom
* @head: pointer to the pointer of a head to a stack
* @counter: line count
*
* Return: (void)
*/
void rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *iterator;

	iterator = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	while (iterator->next)
	{
		iterator = iterator->next;
	}

	iterator->next = *head;
	iterator->prev->next = NULL;
	iterator->prev = NULL;
	(*head)->prev = iterator;
	(*head) = iterator;
}
