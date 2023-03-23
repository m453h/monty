#include "monty.h"

/**
* addnode - function that adds node to the head stack
* @head: pointer to the pointer of a head to a stack_t
* @n: new value
*
* Return: nothing
*/
void addnode(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (temp)
		temp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
* f_queue - prints the top of the queue
* @head: pointer to the pointer of a head to a stack_t
* @counter: line count
*
* Return: (void)
*/
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.type = 1;
}

/**
* addqueue - adds node to queue tail
* @n: value of tail
* @head: pointer to the pointer of a head to a stack_t
*
* Return: (void)
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
