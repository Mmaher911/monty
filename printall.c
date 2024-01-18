#include "monty.h"
/**
 * print_stack - Prints the elements in the stack.
 * @stack: Pointer to the head of the stack.
 * @unused_counter: Not used (placeholder for line number).
 *
 * Description: This function prints the elements in the stack.
 *
 * Return: No explicit return value.
 */
void print_stack(stack_t **stack, unsigned int unused_counter)
{
	stack_t *h;
	(void)unused_counter;

	h = *stack;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
