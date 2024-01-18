#include "monty.h"
/**
 * print_string_from_top - Prints the string
 *
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 *
 * Description: This function interprets the values on the stack
 *
 * Return: No explicit return value.
 */
void print_string_from_top(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *stack;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
