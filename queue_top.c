#include "monty.h"
/**
 * queue_top - Prints the top.
 * @stack: Pointer to the head.
 * @line_number: Line number.
 *
 * Description: Prints the top of the stack.
 *
 * Return: No explicit return.
 */
void queue_top(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	bus.lifi = 1;
}

/**
 * add_queue_node - Add node to the tail.
 * @new_value: New value.
 * @stack_head: Head of the stack.
 *
 * Description: Adds a new node to the tail of the stack.
 *
 * Return: No explicit return.
 */
void add_queue_node(stack_t **new_value, int stack_head)
{
	stack_t *new_node, *aux;

	aux = *new_value;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = stack_head;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*new_value = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
