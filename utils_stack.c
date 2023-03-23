#include "monty.h"

/**
* free_stack - function that frees stack_t from memory
* @head: pointer to the head of the stack
*
* Return: (void)
*/
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
* f_stack - function that prints the top
* @head: head of stack
* @counter: number of lines
*
* Return: (void)
*/
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.type = 0;
}

/**
* f_push - function that adds a node to a stack
* @head: pointer to the pointer of a head to a stack
* @counter: number of lines
*
* Return: (void)
*/
void f_push(stack_t **head, unsigned int counter)
{
	int i, m = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			m++;
		for (; bus.arg[m] != '\0'; m++)
		{
			if (bus.arg[m] > 57 || bus.arg[m] < 48)
				flag = 1; }
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	i = atoi(bus.arg);
	if (bus.type == 0)
		addnode(head, i);
	else
		addqueue(head, i);
}

/**
* f_pall - function that prints all items in the stack
* @head: pointer to the pointer of a head to a stack
* @counter: unused number of line(s)
*
* Return: (void)
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;

	if (h == NULL)
	{
		return;
	}

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
