#include "monty.h"
/**
 * rotate_stack_right - Rotates the stack to the bottom.
 * @stack: Pointer to the head.
 * @line_number: Line number.
 *
 * Description Rotates the stack to move the top element to the end.
 *
 * Return: No explicit return.
 */
void rotate_stack_right(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *copy;

	copy = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}
