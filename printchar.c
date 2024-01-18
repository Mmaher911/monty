#include "monty.h"
/**
 * print_char_at_top - Prints the character at the top of the stack
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 *
 * Description: This function prints the character at the top of the stack
 *
 * Return: No explicit return value.
 */
void print_char_at_top(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	h = *stack;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
