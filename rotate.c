#include "monty.h"
/**
 * rotate_stack_left - Rotates the stack to the top.
 * @stack: Pointer to the head.
 * @line_number: Line number.
 *
 * Description: Rotates the stack to bring the top element to the front.
 *
 * Return: No explicit return.
 */
void rotate_stack_left(stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack, *aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	aux = (*stack)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = aux;
}
