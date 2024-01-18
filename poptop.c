#include "monty.h"
/**
 * pop_top_element - Removes the top element from the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 * Description: This function removes the top element from the stack.
 *
 * Return: No explicit return value.
 */
void pop_top_element(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	*stack = h->next;
	free(h);
}
