#include "monty.h"
/**
 * multiply_top_two_elements - Multiplies the top two elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 *
 * Description:
 * This function multiplies the top two elements of the stack. It takes the top
 * two elements, removes them from the stack, multiplies them, and pushes
 * the result back. The operation is performed in-place on the given stack.
 *
 * Return: No explicit return value.
 */
void multiply_top_two_elements(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*stack = h->next;
	free(h);
}
