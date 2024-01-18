#include "monty.h"
/**
 * swap_top_elements - Swaps the top two elements.
 * @stack: Pointer to the head.
 * @line_number: Line number.
 *
 * Description: Swaps the positions of the top two elements in the stack.
 *
 * Return: No explicit return.
 */
void swap_top_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int len = 0, aux;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
