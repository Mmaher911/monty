#include "monty.h"
/**
 * add_node_to_stack - Adds a new node to the head of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @new_value: Value to be assigned to the new node.
 *
 * Description: This function adds a new node to the head of the stacK
 * Return: No explicit return value.
 */
void add_node_to_stack(stack_t **stack_head, int new_value)
{
	stack_t *new_node, *aux;

	aux = *stack_head;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = new_value;
	new_node->next = *stack_head;
	new_node->prev = NULL;
	*stack_head = new_node;
}
