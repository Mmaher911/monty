#include "monty.h"
/**
 * divide_top_two_elements - Divides the top two elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 *
 * Description: This function divides the top two elements of the stack.
 *
 * Return: No explicit return value.
 */
void divide_top_two_elements(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*stack = h->next;
	free(h);
}
